# Phase 4: API / Interface Design — b6plus 1.174

**نسخه:** 1.174  
**تاریخ:** 2026-09-27  
**فاز:** ۴ از ۱۱  
**هدف:** تعریف مرزهای معماری دقیق، ماتریس وابستگی، و subsystem بندی برای فازهای ۵–۹

---

## ۱. نقشه‌ی ۱۳ Subsystem (درست‌شده)

| # | Subsystem | توابع اصلی | متغیرهای State | خط شروع (تقریبی) |
|---|---|---|---|---|
| 1 | **Navigation / Slide Engine** | `displaySlide`, `makeCurrent`, `nextSlide`, `previousSlide`, `firstSlide`, `lastSlide`, `findSlide`, `targetSlide`, `scrollSlide`, `updateProgress`, `initProgress`, `numberSlides`, `isStartOfSlide`, `undisplaySlide` | `curslide`, `numslides`, `interactive`, `progressElts`, `slidenumElts`, `numslidesElts`, `hoverOverlay`, `scale` | ۱۴۴۰–۲۷۵۰ |
| 2 | **Mode Toggle State Machine** | `toggleMode`, `finishToggleMode`, `toggleModeAndFullscreen`, `toggleFullscreen`, `fullscreenChanged` | `slidemode`, `switchInProgress`, `fullmode`, `switchFullscreen`, `useApplication`, `limit` | ۱۵۱۰–۲۳۸۰ |
| 3 | **Input System** | `keyDown`, `mouseButtonClick`, `doubleClick`, `gestureStart`, `gestureMove`, `gestureEnd`, `gestureCancel`, `recordMousePosition`, `hideMouse`, `hideMouseReset`, `initHideMouse`, `ignoreEvent` | `gesture`, `noclick`, `hideMouseTime`, `hideMouseID`, `singleClickTimer`, `mouseX`, `mouseY` | ۱۹۴۲–۲۷۶۶ |
| 4 | **Second Window Contract** | `openSecondWindow`, `message`, `checkIfSecondWindow`, `beforeUnload` | `secondwindow`, `firstwindow`, `commentsWereVisible` | ۱۷۴۳–۳۱۶۳ |
| 5 | **SSE Sync Contract** | `tryToggleSync`, `syncHandler`, `syncSlide`, `errorSyncMode`, `warnSyncMode` | `syncmode`, `syncURL`, `eventsource` | ۱۷۸۸–۳۰۲۷ |
| 6 | **Session Clock** | `updateClocks`, `requestClocksUpdate`, `addMinute`, `subtractMinute`, `pauseTime`, `resetTime`, `initClocks`, `timeToMillisec` | `startTime`, `pauseStartTime`, `clockElts`, `fullclockElts`, `realHoursElts`, `realMinutesElts`, `realSecondsElts`, `usedHoursElts`, `usedMinutesElts`, `usedSecondsElts`, `leftHoursElts`, `leftMinutesElts`, `leftSecondsElts`, `clockTimer`, `duration`, `warnTime`, `forceClocks`, `clocksUpdateRequested` | ۶۲۱–۷۹۰ |
| 7 | **Automatic Slide Timer** | `pauseAutomaticSlides`, `unpauseAutomaticSlides` | `slideTimer`, `slideTiming`, `slideTimerPaused`, `loopSlideShow` | ۱۸۶۶–۱۸۷۹ |
| 8 | **Feature Managers (۶ زیربخش)** | | | |
| 8a | — Incrementals | `initIncrementals`, `nextSlideOrElt`, `previousSlideOrElt` | `incrementals`, `incrementalsBehavior` | ۲۱۸۳–۲۳۲۰ |
| 8b | — Comments/Notes | `toggleComments`, `trackVisibleSlides` | `commentsVisible`, `commentsDefault`, `visibleSlide` | ۳۵۰۳–۳۵۷۲ |
| 8c | — Table of Contents | `createTOCText`, `tableOfContents`, `getSlideTitle` | `toctext`, `tocItems` | ۲۳۶۵–۲۴۳۵ |
| 8d | — Help Text | `createHelpText`, `help` | `helptext` | ۲۴۴۲–۲۵۰۰ |
| 8e | — Dark Mode | `toggleDarkMode`, `initDarkMode` | `hasDarkMode` | ۲۵۱۵–۲۶۲۵ |
| 8f | — Drawing/Canvas | `toggleAnnotate`, `instrumentVideos` | `canvas`, `canvasContext`, `canvasX`, `canvasY` | ۲۶۳۱–۲۷۶۶ |
| 9 | **Toolbar / UI** | `addUI`, `*ButtonClick` (۹ تابع دکمه) | (بدون state مستقل — فقط dispatcher) | ۳۱۹۵–۳۴۳۲ |
| 10 | **Accessibility Contract** | `speak`, `speakIt`, `initLiveRegion` | `liveregion`, `savedContent`, `lastSpoken`, `slideCopy`, `commentCopy` | ۱۳۵۲–۳۶۱۰ |
| 11 | **URL / Hash Contract** | `hashchange`, `checkURL`, `showURL` | `syncURL`, `commentsDefault` | ۲۸۰۸–۳۳۴۳ |
| 12 | **Cross-cutting / Global** | `initLanguage`, `checkOptions`, `checkIfFramed`, `autosize`, `textFit`, `hideElement`, `unhideElement`, `setStyle`, `cloneNodeClean`, `windowResize`, `checkIfFramed`, `recordMousePosition` | `language`, `stylesToLoad` | ۳۳۲–۶۲۰ |
| 13 | **Initialization** | `initialize`, `initializeLayout` | (shared setup) | ۳۶۱۲–۳۶۷۳ |

---

## ۲. ماتریس کامل Reader/Writer (۶۹ متغیر Global)

### ۲.۱ Navigation State (۸ متغیر)

| متغیر | Reader | Writer | نوع | شرح |
|---|---|---|---|---|
| `curslide` | `displaySlide`, `makeCurrent`, `message`, `doubleClick`, `nextSlide`, `previousSlide`, `updateClocks` | `makeCurrent`, `doubleClick`, `message` | number | اسلاید فعلی (۱-indexed) |
| `numslides` | `displaySlide`, `undisplaySlide`, `updateProgress`, `nextSlide`, `lastSlide` | `numberSlides` | number | تعداد کل اسلایدها |
| `interactive` | `initialize` | `checkOptions` | boolean | آیا ناوبری فعال است (نه static) |
| `progressElts` | `updateProgress` | `numberSlides` | NodeList | عناصر با class="progress" |
| `slidenumElts` | `updateProgress` | `numberSlides` | NodeList | عناصر با class="slidenum" |
| `numslidesElts` | `numberSlides` (display), `updateProgress` | `numberSlides` | NodeList | عناصر با class="numslides" |
| `hoverOverlay` | `showURL` | `addUI` | HTMLElement | overlay برای نمایش URL |
| `scale` | `displaySlide`, `undisplaySlide` | `windowResize`, `displaySlide` | number | scale factor برای slide mode |

### ۲.۲ Mode Toggle State Machine (۶ متغیر)

| متغیر | Reader | Writer | نوع | شرح |
|---|---|---|---|---|
| `slidemode` | `displaySlide`, `keyDown`, `toggleMode`, `initialize`, بسیاری دیگر | `toggleMode`, `finishToggleMode`, `checkURL` | boolean | آیا در slide mode هستیم |
| `switchInProgress` | `keyDown`, `toggleMode` | `toggleMode`, `finishToggleMode` | boolean | آیا transition در حال‌اجرا است |
| `fullmode` | `toggleMode`, `initialize` | `toggleMode`, `toggleFullscreen`, `fullscreenChanged` | boolean | آیا fullscreen است |
| `switchFullscreen` | `toggleFullscreen` | `toggleFullscreen` | boolean | درخواست toggle fullscreen |
| `useApplication` | none | `checkOptions` | boolean | استفاده از role=application (accessibility) |
| `limit` | `displaySlide`, `autosize` | `checkOptions`, `windowResize` | number | محدودیت عرض/ارتفاع برای slide |

### ۲.۳ Input System (۷ متغیر)

| متغیر | Reader | Writer | نوع | شرح |
|---|---|---|---|---|
| `gesture` | `gestureStart`, `gestureMove`, `gestureEnd`, `gestureCancel` | `gestureStart` | object | وضعیت gesture فعلی |
| `noclick` | `mouseButtonClick`, `doubleClick`, `gestureEnd`, `toggleAnnotate` | `checkOptions` | boolean | جلوگیری از navigation با کلیک |
| `hideMouseTime` | `hideMouse`, `hideMouseReset`, `recordMousePosition` | `recordMousePosition` | number | timeout برای مخفی کردن ماوس |
| `hideMouseID` | `hideMouseReset`, `recordMousePosition` | `recordMousePosition` | number | ID timeout |
| `singleClickTimer` | `mouseButtonClick` | `mouseButtonClick` | number | برای تفکیک single/double click |
| `mouseX` | `recordMousePosition`, `showURL` | `recordMousePosition` | number | X position ماوس |
| `mouseY` | `recordMousePosition`, `showURL` | `recordMousePosition` | number | Y position ماوس |

### ۲.۴ Second Window Contract (۳ متغیر)

| متغیر | Reader | Writer | نوع | شرح |
|---|---|---|---|---|
| `secondwindow` | `message`, `checkIfSecondWindow`, `initialize` | `openSecondWindow`, `message`, `beforeUnload` | Window | reference به پنجره‌ی دوم |
| `firstwindow` | بسیاری | `message` (در پنجره‌ی دوم) | Window | reference به پنجره‌ی اول |
| `commentsWereVisible` | `beforeUnload` | `message` | boolean | برای restore تنظیمات بعد بسته شدن |

### ۲.۵ SSE Sync Contract (۳ متغیر)

| متغیر | Reader | Writer | نوع | شرح |
|---|---|---|---|---|
| `syncmode` | `keyDown`, `tryToggleSync`, `warnSyncMode`, `message` | `tryToggleSync`, `message` | boolean | آیا sync فعال است |
| `syncURL` | `tryToggleSync`, `syncSlide`, `checkURL` | `checkOptions`, `checkURL` | string | URL سرور sync |
| `eventsource` | `tryToggleSync`, `errorSyncMode` | `tryToggleSync`, `syncHandler` | EventSource | connection به سرور |

### ۲.۶ Session Clock (۱۸ متغیر)

| متغیر | Reader | Writer | نوع | شرح |
|---|---|---|---|---|
| `startTime` | `updateClocks`, `timeToMillisec` | `message`, `initClocks` | number | timestamp شروع (milliseconds) |
| `pauseStartTime` | `updateClocks`, `timeToMillisec` | `message`, `pauseTime`, `resetTime`, `initClocks` | number | timestamp pause |
| `clockElts` | `updateClocks`, `initClocks` | `initClocks` | Array | عناصر ساعت |
| `fullclockElts` | `updateClocks`, `initClocks` | `initClocks` | Array | عناصر ساعت کامل |
| `realHoursElts` | `updateClocks` | `initClocks` | Array | عناصر ساعت واقعی (ساعت) |
| `realMinutesElts` | `updateClocks` | `initClocks` | Array | عناصر ساعت واقعی (دقیقه) |
| `realSecondsElts` | `updateClocks` | `initClocks` | Array | عناصر ساعت واقعی (ثانیه) |
| `usedHoursElts` | `updateClocks` | `initClocks` | Array | عناصر مدت استفاده (ساعت) |
| `usedMinutesElts` | `updateClocks` | `initClocks` | Array | عناصر مدت استفاده (دقیقه) |
| `usedSecondsElts` | `updateClocks` | `initClocks` | Array | عناصر مدت استفاده (ثانیه) |
| `leftHoursElts` | `updateClocks` | `initClocks` | Array | عناصر باقی‌مانده (ساعت) |
| `leftMinutesElts` | `updateClocks` | `initClocks` | Array | عناصر باقی‌مانده (دقیقه) |
| `leftSecondsElts` | `updateClocks` | `initClocks` | Array | عناصر باقی‌مانده (ثانیه) |
| `clockTimer` | `updateClocks`, `resetTime`, `initClocks` | `updateClocks`, `initClocks`, `resetTime`, `pauseTime` | number | interval ID برای update |
| `duration` | `updateClocks`, `timeToMillisec` | `message`, `initClocks` | number | مدت کل (milliseconds) |
| `warnTime` | `updateClocks` | `initClocks` | number | زمان هشدار (milliseconds) |
| `forceClocks` | `initClocks` | `message` | boolean | بازگذاری ساعت از پنجره‌ی دوم |
| `clocksUpdateRequested` | `updateClocks` | `requestClocksUpdate` | boolean | درخواست update |

### ۲.۷ Automatic Slide Timer (۴ متغیر)

| متغیر | Reader | Writer | نوع | شرح |
|---|---|---|---|---|
| `slideTimer` | `displaySlide`, `pauseAutomaticSlides`, `unpauseAutomaticSlides` | `displaySlide`, `pauseAutomaticSlides`, `unpauseAutomaticSlides` | number | timeout ID |
| `slideTiming` | `pauseAutomaticSlides`, `unpauseAutomaticSlides` | `displaySlide` | number | delay بین اسلایدها (ms) |
| `slideTimerPaused` | `displaySlide`, `message` | `pauseAutomaticSlides`, `unpauseAutomaticSlides`, `message` | boolean | آیا پاز است |
| `loopSlideShow` | `nextSlide` | `displaySlide`, `checkOptions` | boolean | بازگشت به اول بعد آخر |

### ۲.۸ Feature Managers (۱۳ متغیر)

| متغیر | Reader | Writer | نوع | شرح |
|---|---|---|---|---|
| `incrementals` | `nextSlideOrElt`, `previousSlideOrElt`, `displaySlide` | `initIncrementals` | Array | عناصر incremental |
| `incrementalsBehavior` | `displaySlide`, `keyDown` | `initIncrementals` | Array | رفتار هر incremental |
| `commentsVisible` | `toggleComments`, `initialize` | `toggleComments`, `message` | boolean | آیا comments نمایش داده شده |
| `commentsDefault` | `initialize`, `checkURL` | `checkOptions`, `checkURL` | boolean | تنظیم پیش‌فرض |
| `visibleSlide` | `toggleComments` | `toggleComments`, `trackVisibleSlides` | Element | آخرین slide نمایان |
| `toctext` | `createTOCText` | `createTOCText` | string | محتوای ToC |
| `tocItems` | `tableOfContents` | `createTOCText` | Array | عناصر ToC |
| `helptext` | `createHelpText`, `help` | `createHelpText` | string | محتوای help |
| `hasDarkMode` | `toggleDarkMode`, `message`, `keyDown` | `initDarkMode` | boolean | پشتیبانی dark mode |
| `canvas` | `toggleAnnotate`, `displaySlide`, `gestureStart`, `gestureMove`, `gestureEnd` | `toggleAnnotate`, `displaySlide` | HTMLCanvasElement | canvas برای رسم |
| `canvasContext` | `gestureStart`, `gestureMove`, `gestureEnd` | `toggleAnnotate` | CanvasRenderingContext2D | context برای رسم |
| `canvasX` | `gestureMove` | `gestureStart`, `gestureMove` | number | X در canvas |
| `canvasY` | `gestureMove` | `gestureStart`, `gestureMove` | number | Y در canvas |

### ۲.۹ Accessibility (۵ متغیر)

| متغیر | Reader | Writer | نوع | شرح |
|---|---|---|---|---|
| `liveregion` | `speak`, `initLiveRegion`, `speakIt` | `initLiveRegion` | HTMLElement | ARIA live region |
| `savedContent` | `toggleComments`, `speakIt` | `initLiveRegion` | Array | محتوای ذخیره‌شده |
| `lastSpoken` | `speak` | `speak` | string | آخرین متنی که خوانده شد |
| `slideCopy` ⚠️ | (none) | (none) | (dead code) | جا افتاده — حذف کاندید |
| `commentCopy` ⚠️ | (none) | (none) | (dead code) | جا افتاده — حذف کاندید |

### ۲.۱۰ Cross-cutting / Global (۲ متغیر)

| متغیر | Reader | Writer | نوع | شرح |
|---|---|---|---|---|
| `language` | `_()`, `initLanguage` | `initLanguage`, `checkOptions` | string | language code (de, fr, nl) |
| `stylesToLoad` | `addUI`, `checkOptions` | `checkOptions` | number | تعداد stylesheets برای load |

---

## ۳. وابستگی‌های بین Subsystemها

### ۳.۱ Coupling پنهان (⚠️ نیاز به setter رسمی در Phase 5)

| تعداد writers | متغیر | Writers | شرح |
|---|---|---|---|
| 3 | `curslide` | Navigation, Input (doubleClick), SecondWindow | **نقطه‌ی خطرناک** — چند جا می‌نویسند |
| 2 | `slidemode` | Mode Toggle, URL/Hash | **Bidirectional** — هم کد، هم URL |
| 2 | `fullmode` | Mode Toggle, Fullscreen event | **Bidirectional** — متعلق هم به Mode Toggle |
| 1 | `commentsVisible` | Comments Feature | **Sync با پنجره‌ی دوم** — اما `message()` آن را می‌خواند |

### ۳.۲ Internal Messaging

**`message()` (Second Window) به‌طور مستقیم وارد قلمروهای دیگر می‌شود:**
- نوشتن `curslide`, `startTime`, `pauseStartTime`, `duration`, `forceClocks` (Session Clock)
- نوشتن `syncmode` (SSE Sync)
- نوشتن `slideTimerPaused`, `commentsVisible` (Features)
- خواندن `hasDarkMode`, `canvas`, `commentsVisible` برای sync

**`keyDown()` یک dispatcher مرکزی است:**
صدا می‌زند:
- Navigation: `nextSlide()`, `previousSlide()`, `findSlide()`
- Mode Toggle: `toggleMode()`, `toggleFullscreen()`
- Input-specific: `hideMouseReset()`, `doubleClick()` handling
- Features: `toggleDarkMode()`, `toggleAnnotate()`, `toggleComments()`, `help()`, `tableOfContents()`
- Sync: `tryToggleSync()`
- Timer: `pauseAutomaticSlides()` / `unpauseAutomaticSlides()`

### ۳.۳ Transitive Dependencies

```
displaySlide() ← Navigation
  → `scale` ← Mode Toggle
  → `canvas` ← Drawing
  → `slideTimer`, `loopSlideShow` ← Auto Timer
  → `incrementals` ← Incrementals Feature

message() ← Second Window
  → `startTime`, `pauseStartTime`, `duration` ← Session Clock
  → `syncmode` ← SSE Sync
  → `slideTimerPaused` ← Auto Timer
```

---

## ۴. Dead Code (حذف کاندید در Phase 5)

| متغیر | خط | تعریف | استفاده | وضعیت |
|---|---|---|---|---|
| `slideCopy` | ۴۸۵ | `let slideCopy;` | **۰** | ⚠️ حذف |
| `commentCopy` | ۴۸۶ | `let commentCopy;` | **۰** | ⚠️ حذف |

---

## ۵. خوشه‌های Phase 3 (var→let) و تأیید آن‌ها

| # | Cluster | تابع | متغیرهای محلی (let شده) | وضعیت |
|---|---|---|---|---|
| 1 | Utility | `_()` | `tr` | ✅ |
| 2 | Timer/Clock | `timeToMillisec()` | `used`, `left` | ✅ |
| 3 | Incremental | `nextSlideOrElt()` | `elts`, `item`, `e` | ✅ |
| 4 | Slide Detection | `isStartOfSlide()` | — (۰ var) | ✅ |
| 5 | Layout | `displaySlide()` | `elts`, `e`, `elt`, `r`, `hastext`, `hasincrementals`, `hascomment` | ✅ |
| 6 | Nav Helpers | `findSlide()` | `id`, `h`, `slides`, `prefix` | ✅ |
| 7 | Display Core | `undisplaySlide()` | `elts`, `e`, `comment` | ✅ |
| 8 | Display Core | `makeCurrent()` | `h` | ✅ |
| 9 | Display Core | `nextSlide()` | — (۰ var) | ✅ |
| 10 | Mode Toggle | `toggleMode()` | `inFullscreen`, `i`, `found`, `e` | ✅ |
| 11 | Mode Toggle | `finishToggleMode()` | — (۰ var) | ✅ |
| 12 | Fullscreen | `toggleFullscreen()` | `elem` | ✅ |
| 13 | Input | `keyDown()` | `e`, `key`, `modname`, `c` | ✅ |
| 14 | Input | `gestureMove()` | `dx`, `dy`, `x`, `y`, `w`, `h` | ✅ |
| 15 | Input | `hideMouseReset()` | — (۰ var) | ✅ |
| 16 | UI | `addUI()` | `btn`, `span`, `attr`, `buttonTexts`, `label`, `tooltip` | ✅ |
| 17 | UI | `createTOCText()` | `id`, `heading`, `text`, `level` | ✅ |
| 18 | UI | `createHelpText()` | `keys`, `key` | ✅ |
| 19 | Sync/Second | `message()` | `e`, `fragment`, `key` | ✅ |
| 20 | Sync/Second | `beforeUnload()` | `response` | ✅ |
| 21 | Media | `instrumentVideos()` | `v`, `a` | ✅ |
| 22 | Accessibility | `trackVisibleSlides()` | `observer` | ✅ |
| 23 | Initialization | `initialize()` | — (۰ var) | ✅ |
| 24 | Global Block | Global variables (خط ۴۵۵–۵۴۳) | ۶۹ متغیر | ✅ |

---

## ۶. Private API (داخل IIFE) — پیشنهادی برای Phase 5–۹

```javascript
// Phase 5: State Extraction
const State = {
  Navigation: {curslide, numslides, interactive, ...},
  ModeToggle: {slidemode, switchInProgress, ...},
  Input: {gesture, noclick, ...},
  // ...
};

// Phase 6–۹: Module-like grouping (still in IIFE, no export)
const Navigation = {
  nextSlide,
  previousSlide,
  displaySlide,
  // ...
};

const ModeToggle = {
  toggleMode,
  finishToggleMode,
  // ...
};

// ... (هیچ module export — فقط سازمان‌دهی درون IIFE)
```

---

## ۷. Public API (window.b6plus) — جدید در Phase 5

```javascript
window.b6plus = {
  // خواندن state (read-only)
  currentSlide: () => curslide,
  totalSlides: () => numslides,
  isSlideMode: () => slidemode,
  
  // عملیات
  nextSlide: nextSlide,
  previousSlide: previousSlide,
  jumpToSlide: (n) => targetSlide(n),
  toggleMode: toggleMode,
  
  // تنظیمات
  setSyncURL: (url) => { syncURL = url; },
  setAutoAdvance: (ms) => { slideTiming = ms; },
  
  // Version
  version: "1.174-modernized",
};
```

---

## ۸. Contracts که نباید شکسته شود

✅ **Incremental elements** — built-up slides  
✅ **Keyboard shortcuts** — A, Space, Arrow, F, S, D, W, C, ?, 2, N  
✅ **Touch gestures** — 3-finger tap, swipe left/right  
✅ **Second Window** — postMessage protocol  
✅ **SSE Sync** — EventSource, URL parameters  
✅ **Fullscreen API** — screen.orientation, fullscreen events  
✅ **Dark Mode** — prefers-color-scheme media query  
✅ **Canvas Drawing** — mouse gesture draw on slides  
✅ **Accessibility** — ARIA live regions, screen reader support  
✅ **Comments** — speaker notes, class="comment" elements  
✅ **URL/Hash** — query params (?full, ?static), location.hash  

---

## ۹. خط‌مشی برای فازهای بعدی (۵–۱۱)

| فاز | کار | تحویل |
|---|---|---|
| 5 | State Extraction — جدا‌کردن متغیرها با setter | comments + `docs/phase5-state-extraction.md` |
| 6 | Navigation/Slide Engine — جدا‌کردن توابع nav | comments + code organization |
| 7 | Input System — جدا‌کردن input handlers | comments + code organization |
| 8 | Feature Managers — جدا‌کردن features | comments + code organization |
| 9 | Toolbar/UI — جدا‌کردن UI code | comments + code organization |
| 10 | New Features — Laser, Resume, Undo/Redo, Dashboard | new code + docs |
| 11 | Testing/Stabilization — تست تمام رفتارها | test report |

---
