# Phase 6: Navigation / Slide Engine — تحلیل دقیق (نسخه نهایی)

**نسخه:** 1.174  
**هدف:** کشف و مدل‌سازی موتور Navigation بدون تغییر کد  

---

## ۱. جدول تحلیلی توابع Navigation (۱۸ تابع - نهایی)

| Function | Line | وظیفه | State Read | State Write | Internal Calls | Side Effects | دسته‌بندی |
|---|---|---|---|---|---|---|---|
| **nextSlideOrElt** | 2428 | رفتن به بعدی (slide یا incremental) | slideTimer, incrementals.cur | incrementals.cur ← | scrollSlide, nextSlide | scroll, classList | **Core Navigation** |
| **previousSlideOrElt** | 2506 | رفتن به قبلی (slide یا incremental) | slidemode, incrementals.cur | incrementals.cur ← | scrollSlide, displaySlide | scroll, classList | **Core Navigation** |
| **nextSlide** | 2480 | رفتن به اسلاید بعدی | loopSlideShow, curslide | — (indirect via makeCurrent) | isStartOfSlide, makeCurrent, scrollSlide | — | **Core Navigation** |
| **previousSlide** | 2540 | رفتن به اسلاید قبلی | curslide, slidemode | — (indirect via makeCurrent) | isStartOfSlide, makeCurrent, scrollSlide | — | **Core Navigation** |
| **targetSlide** | 2610 | رفتن به اسلاید خاص | — | — (indirect via makeCurrent) | findSlide, makeCurrent | visibility | **Core Navigation** |
| **makeCurrent** | 1491 | تعیین اسلاید فعلی (state changer) | — | curslide ← | displaySlide, undisplaySlide | visibility | **Core Mutation** |
| **displaySlide** | 1433 | نمایش اسلاید | curslide, slideTimerPaused, slideTiming, incrementals.length | slideTimer ← | updateProgress, initIncrementals, speak, firstwindow.postMessage, setURL, scheduleVideos, rewindVideos | classList, visibility, progress UI, incremental init, URL/hash, video control, cross-window messaging, timer scheduling | **Core Mutation** |
| **undisplaySlide** | 1474 | مخفی کردن اسلاید | curslide | — | stopVideos | classList, visibility, media stop, DOM state | **Core Mutation** |
| **scrollSlide** | 2406 | Viewport/Overflow management داخل slide | scale, curslide, incrementals.cur | — | — | scroll operation, viewport adjustment | **Viewport Mgmt** |
| **isStartOfSlide** | 950 | بررسی آیا element شروع slide است | — | — | — | DOM read (classList, attributes), CSS detection | **Slide Detection** |
| **findSlide** | 2593 | جستجو برای slide (by ID یا number) | — | — | — | DOM traversal, getElementById | **Slide Detection** |
| **numberSlides** | 1006 | شناسایی و شمارش slides + initialization | — | numslides ← | isStartOfSlide | CSS counter, b6slidenum setting, ID generation, DOM queries (progressElts, slidenumElts, numslidesElts) | **Slide Discovery** |
| **updateProgress** | 963 | آپدیت progress bar | curslide, numslides | — | — | innerHTML/textContent, DOM content | **UI Update** |
| **initProgress** | 987 | UI initialization / unhide | numslides | — | — | unhide existing elements, DOM state | **UI Init** |
| **toggleMode** | 2238 | تغییر slide/normal mode | slidemode | slidemode ← | isStartOfSlide | classList.toggle(.full), animation setup | **Mode Switch** |
| **finishToggleMode** | 2194 | Mode switch finalization / initialization | scale, curslide, incrementals.cur | — | scrollSlide, initProgress | classList changes, animation cleanup | **Mode Switch** |
| **toggleFullscreen** | 1522 | Toggle browser fullscreen | — | switchFullscreen ← | — | fullscreen API call | **Fullscreen** |
| **fullscreenChanged** | (event handler) | Fullscreen state change handler | — | — | — | browser/DOM event handling | **Fullscreen** |

---

## ۲. Dependency Tree (نهایی - اصلاح شده)

### ۲.۱ Core Navigation Flow:

```
┌─────────────────────────────────────────────────────────────┐
│              Navigation Engine (Core API)                   │
│  User/Input triggered navigation                           │
└───────────────────────────┬─────────────────────────────────┘
                            │
        ┌───────────────────┼───────────────────┐
        │                   │                   │
   nextSlideOrElt       previousSlideOrElt     targetSlide
        │ (increment-aware) │ (increment-aware) │
        │                   │                   │
        └────────┬──────────┴──────────┬────────┘
                 │                     │
           [increment?]            [lookup]
              /  \                    │
            /      \            findSlide(n/id)
           /        \                │
    scroll/speak   nextSlide    ─────┘
                    │
              isStartOfSlide()
                    │
           ┌────────┴─────────┐
           │                  │
      makeCurrent()       [if needed]
           │
     ┌─────┴──────────┐
     │                │
displaySlide()    undisplaySlide()
     │                │
     ├─ updateProgress()  ├─ stopVideos()
     ├─ initIncrementals()│
     ├─ speak()           │
     ├─ setURL()          │
     ├─ postMessage()     │
     ├─ scheduleVideos()  │
     ├─ rewindVideos()    │
     ├─ slideTimer ←      │
     └─ [15+ side effects]└─ classList changes
```

### ۲.۲ Fullscreen Flow:

```
toggleFullscreen() ──→ browser fullscreen API
                         │
                         └→ fullscreenChanged() (event handler)
```

### ۲.۳ Mode Toggle Flow:

```
toggleMode()
    │
    ├─ slidemode ←
    ├─ isStartOfSlide()
    ├─ animation setup
    │
    └─ [animation frame] ──→ finishToggleMode()
                               │
                               ├─ scrollSlide()
                               └─ initProgress()
```

---

## ۳. State Management (نهایی)

### State Readers (Read-Only):

| State | Readers | نوع وابستگی |
|---|---|---|
| `curslide` | nextSlide, previousSlide, updateProgress, scrollSlide, toggleMode, finishToggleMode, displaySlide | **CRITICAL** — هسته Navigation |
| `incrementals.cur` | nextSlideOrElt, previousSlideOrElt, scrollSlide, finishToggleMode | **CRITICAL** — incremental state |
| `numslides` | updateProgress, initProgress | bounds checking |
| `slideTimerPaused` | displaySlide | timer control condition |
| `slideTiming` | displaySlide | auto-advance timing config |
| `incrementals.length` | displaySlide | initialization condition |
| `slidemode` | previousSlide, nextSlideOrElt, toggleMode | decision logic |
| `scale` | scrollSlide, finishToggleMode | zoom factor |
| `loopSlideShow` | nextSlide | wrap-around mode |

### State Writers (Direct Mutation):

| State | Writers | Effect |
|---|---|---|
| `curslide` | makeCurrent | **DIRECT WRITE** — slide index |
| `incrementals.cur` | nextSlideOrElt, previousSlideOrElt | **DIRECT WRITE** — progressive disclosure |
| `numslides` | numberSlides | initialization only |
| `slidemode` | toggleMode | mode switching |
| `slideTimer` | displaySlide | auto-advance timing |
| `switchFullscreen` | toggleFullscreen | fullscreen state |

### Critical Path 1: User presses →

```
keyDown() detects arrow
    ↓
nextSlideOrElt() called
    ├─ if incrementals.cur < max:
    │  ├─ incrementals.cur++          ← DIRECT WRITE
    │  ├─ scrollSlide()               ← viewport adjustment
    │  └─ speak()                     ← a11y
    │
    └─ else:
       ├─ nextSlide()                 ← API call
       │  ├─ isStartOfSlide() check
       │  └─ makeCurrent()             ← DIRECT WRITE curslide
       │     ├─ undisplaySlide()
       │     │  └─ stopVideos()
       │     └─ displaySlide()
       │        ├─ updateProgress()
       │        ├─ initIncrementals()
       │        ├─ speak()
       │        ├─ setURL()
       │        ├─ postMessage()
       │        ├─ rewindVideos()
       │        └─ slideTimer ← if slideTiming
       └─ scrollSlide()
```

### Critical Path 2: targetSlide(n) — Direct Jump

```
targetSlide(n)
    │
    ├─ findSlide(n)       ← ID lookup or b6slidenum match
    │  └─ return elt
    │
    └─ makeCurrent(elt)   ← DIRECT WRITE curslide
       ├─ undisplaySlide()
       │  └─ stopVideos()
       └─ displaySlide()
          ├─ updateProgress()
          ├─ initIncrementals()
          ├─ speak()
          ├─ setURL()
          ├─ postMessage()
          ├─ rewindVideos()
          └─ slideTimer ← if slideTiming
```

### Critical Path 3: displaySlide() Full Scope

```
displaySlide(slide)
    │
    ├─ READ: curslide, slideTimerPaused, slideTiming, incrementals.length
    ├─ WRITE: slideTimer ←
    │
    ├─ classList.add("active")
    ├─ displayChildren(slide) → recursion
    │
    ├─ updateProgress()              → progress bar content
    ├─ initIncrementals()            → b6increment state
    ├─ speak(slide)                  → a11y announcements
    ├─ setURL(slide)                 → history/hash management
    ├─ firstwindow?.postMessage()    → cross-window sync
    ├─ scheduleVideos(slide)         → media resource prep
    ├─ rewindVideos(slide)           → video/audio reset
    │
    ├─ if slideTiming > 0 && !slideTimerPaused:
    │  └─ slideTimer = setTimeout(nextSlideOrElt, slideTiming)
    │
    └─ [side effects complete]
```

---

## ۴. Highly-Coupled, Multi-Responsibility Function: displaySlide()

### شواهد Coupling:

```
displaySlide() Dependencies & Responsibilities:

State Reads:
├─ curslide (navigation context)
├─ slideTimerPaused (auto-advance control)
├─ slideTiming (auto-advance timing)
└─ incrementals.length (progressive disclosure)

State Writes:
└─ slideTimer (auto-advance scheduling)

Internal Function Calls:
├─ updateProgress() → progress bar management
├─ initIncrementals() → b6increment subsystem
├─ speak() → accessibility/a11y
├─ setURL() → URL/hash contract
├─ firstwindow.postMessage() → second window contract
├─ scheduleVideos() → media subsystem
└─ rewindVideos() → media subsystem

DOM Mutations:
├─ classList.add("active")
├─ style.display = "block"
├─ displayChildren() recursion
└─ indirect DOM changes via updateProgress()

Subsystems Coupled:
├─ UI Progress
├─ Incremental Navigation
├─ Accessibility (a11y)
├─ URL/Hash Management
├─ Cross-Window Sync
├─ Media Control
└─ Timer Scheduling
```

### نتیجه:

displaySlide() است که:
- **۷ subsystem مختلف** را مدیریت می‌کند
- **۵+ state متغیر** را می‌خواند/می‌نویسد
- **۷+ تابع داخلی** را فراخوانی می‌کند
- **DOM و API** را مستقیماً تغییر می‌دهد

**این شواهد واضح برای یک function با مسئولیت‌های متعدد است** که نیاز به جداسازی در Phase 10-11 دارد.

---

## ۵. Subsystem Organization (۱۸ تابع)

### Navigation Core (۵ توابع):
- nextSlideOrElt
- previousSlideOrElt
- nextSlide
- previousSlide
- targetSlide

### Core Mutation (۳ توابع):
- makeCurrent
- displaySlide
- undisplaySlide

### Slide Detection/Discovery (۳ توابع):
- isStartOfSlide (boundary detection)
- findSlide (lookup)
- numberSlides (discovery + init)

### Utilities (۴ توابع):
- scrollSlide (viewport management)
- updateProgress (UI update)
- initProgress (UI initialization)
- toggleMode (mode switching)

### Mode Switch Completion (ہ تابع):
- finishToggleMode (animation finalization + initialization)

### Fullscreen (۲ تابع):
- toggleFullscreen (browser API)
- fullscreenChanged (event handler)

---

## ۶. نقاط حرج برای Phases 7-11

### ✅ Phase 7: Input System
- keyDown dispatcher → nextSlideOrElt/previousSlideOrElt
- targetSlide routing (click, hash)
- Mouse/touch incremental detection

### ✅ Phase 8-9: Feature Managers
- Separate incremental management from navigation
- Separate progress bar from displaySlide
- Media subsystem extraction

### ✅ Phase 10-11: Refactoring displaySlide()
**Decomposition Path:**
1. Extract updateProgress() → Progress Manager
2. Extract initIncrementals() → Incremental Manager
3. Extract speak() → Accessibility Contract
4. Extract setURL() → URL/Hash Contract
5. Extract postMessage() → Second Window Contract
6. Extract video control → Media Manager
7. Keep core displaySlide() → pure DOM visibility

**Result:** displaySlide() becomes:
```javascript
function displaySlide(slide) {
  // Pure mutation
  classList.add("active");
  style.display = "block";
  displayChildren(slide);
  
  // Subsystem notifications (via events or callbacks)
  onSlideDisplayed(slide);
}
```

---

## ۷. نتیجه‌گیری Phase 6

### تصمیمات حاصل:

| موضوع | نتیجه |
|---|---|
| تعداد توابع Navigation | **۱۸** (نه ۱۶) |
| nextSlideOrElt/previousSlideOrElt | **Core Navigation** (direct incrementals.cur write) |
| displaySlide | **Highly-coupled, multi-responsibility** (۷ subsystem) |
| curslide mutation | **Indirect** (via makeCurrent) در slide navigation |
| incrementals.cur mutation | **Direct** (در nextSlideOrElt/previousSlideOrElt) |
| State vs Side Effects | **بسیار intertwined** — جداسازی در Phase 10-11 |

### کامنت‌های کد نهایی:

```javascript
/* ===== Navigation / Slide Engine (Core) ===== */
// API Entry Points (User/Input triggered - 18 functions total):
//   Increment-aware: nextSlideOrElt(), previousSlideOrElt()
//   Slide-level: nextSlide(), previousSlide(), targetSlide()
//   State changer: makeCurrent() [WRITES curslide directly]
//   Display control: displaySlide() [highly-coupled, 7 subsystems]
//                   undisplaySlide() [media control]
//
// Slide Detection (DOM predicates/queries):
//   isStartOfSlide(elt) - boundary detection
//   findSlide(id/num) - independent lookup (no numslides dependency)
//   numberSlides() - discovery + initialization
//
// Utilities:
//   scrollSlide() - viewport/overflow management
//   updateProgress() - progress bar content
//   initProgress() - UI initialization / unhide
//   toggleMode() - mode switching
//   finishToggleMode() - mode switch finalization
//
// Fullscreen:
//   toggleFullscreen() - browser fullscreen API
//   fullscreenChanged() - event handler
//
// CRITICAL: displaySlide() is highly-coupled (reads/writes multiple states,
// calls 7+ functions, affects 7 subsystems). Requires decomposition in Phase 10-11.
//
// State: curslide, incrementals.cur, numslides, slideTimerPaused,
//        slideTiming, incrementals.length, slidemode, scale, loopSlideShow
```

---

