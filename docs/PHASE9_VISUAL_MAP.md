# Phase 9: Toolbar/UI — Visual Architecture Map

---

##  Complete System Architecture (Phases 5-9)

```
┌─────────────────────────────────────────────────────────────────────────────┐
│                          USER INTERACTIONS                                  │
│                  (Keyboard, Mouse, Touch, Timer Events)                      │
└─────────────────────────────────────┬───────────────────────────────────────┘
                                      ↓
┌─────────────────────────────────────────────────────────────────────────────┐
│                    PHASE 7: INPUT SYSTEM (12 handlers)                       │
│  keyDown() → Feature routing (C, D, W, ?)                                   │
│  Mouse input → Drawing (annotation)                                        │
│  Timer callback → Auto-advance                                              │
└─────────────────────────────────────┬───────────────────────────────────────┘
                                      ↓
┌─────────────────────────────────────────────────────────────────────────────┐
│                  PHASE 8: FEATURE MANAGERS (6 subsystems)                   │
│  Incrementals, Comments, TOC, Help, Dark Mode, Annotation                  │
│  Coupling: Triggered via keyDown, use displaySlide for state updates       │
└─────────────────────────────────────┬───────────────────────────────────────┘
                                      ↓
┌─────────────────────────────────────────────────────────────────────────────┐
│               PHASE 9: TOOLBAR / UI (19 functions, 18 variables)            │
│                                                                               │
│  5 Categories:                                                               │
│  1. Core Display (7):    displaySlide [GOD], updateProgress, etc.           │
│  2. Control (2):         hideMouseReset, initHideMouse                      │
│  3. Panels (5):          help, TOC, Comments, getTitle, createTOC          │
│  4. Mode (5):            toggleMode, toggleDarkMode, toggleFullscreen      │
│  5. Annotation (1):      toggleAnnotate                                     │
│                                                                               │
│  State (18 vars):                                                            │
│  Display: progressElts, slidenumElts, scale                                 │
│  Features: commentsVisible, helptext, toctext, canvas*4                     │
│  Mode: slidemode, fullmode, hasDarkMode                                     │
│  Global: language, stylesToLoad                                             │
│                                                                               │
│  Key Problem: displaySlide() mixes Navigation + Features + UI               │
│               + Accessibility → GOD FUNCTION                                 │
└─────────────────────────────────────┬───────────────────────────────────────┘
                                      ↓
┌─────────────────────────────────────────────────────────────────────────────┐
│                PHASE 6: NAVIGATION + MODE TOGGLE SYSTEMS                    │
│  Navigation: nextSlide, previousSlide, targetSlide, makeCurrent             │
│  Mode: toggleMode, finishToggleMode, toggleFullscreen                       │
│  Coupling: displaySlide() bridges Navigation → UI                           │
└─────────────────────────────────────┬───────────────────────────────────────┘
                                      ↓
┌─────────────────────────────────────────────────────────────────────────────┐
│                    PHASE 5: GLOBAL STATE (69 variables)                     │
│  Navigation, Input, Feature, Mode, Session, Sync, etc.                     │
└─────────────────────────────────────────────────────────────────────────────┘
                                      ↓
                            [DOM RENDERING]
                          [HTML / CSS / Canvas]
```

---

## 🔀 UI Entry Points Flow Diagram

```
                            INPUT SYSTEM
                                 ↓
        ┌────────────────────────┼────────────────────────┐
        ↓                        ↓                        ↓
    NAVIGATION                FEATURES                 TIMER
        ↓                        ↓                        ↓
    nextSlide()            keyDown('C','D','W')    slideTimer
    previousSlide()               ↓                   callback
    targetSlide()          ┌──────┼──────┐             ↓
        ↓                  ↓      ↓      ↓          nextSlide()
    makeCurrent()      toggle   toggle  toggle          ↓
        ↓              Comments DarkMode Annotate    makeCurrent()
    displaySlide()         ↓      ↓      ↓             ↓
        ↓                  ↓      ↓      ↓         displaySlide()
    ┌───┴───┐               ├──────┴──────┤             ↓
    ↓       ↓               ↓             ↓         updateProgress()
 update  init        initDarkMode()  toggleAnnotate()  ↓
Progress Progress        ↓               ↓        [UI Updated]
    ↓       ↓        body.classList  canvas
    ↓       ↓        postMessage()    events
    ↓       ↓           [BREACH]      [draw]
    │       └────────────┬────────────┘
    │                    ↓
            ┌────────────────────────┐
            │   DOM RENDERING        │
            ├────────────────────────┤
            │ classList: 70+ calls   │
            │ style.width: 114+ call │
            │ innerHTML: 9+ calls    │
            │ textContent: 18+ calls │
            └────────────────────────┘
                        ↓
                  [VISUAL OUTPUT]
```

---

## 📊 Function Classification Tree

```
UI SUBSYSTEM (19 Functions)
├─ Category 1: CORE DISPLAY (7)
│  ├─ displaySlide()       [GOD FUNCTION]
│  ├─ makeCurrent()        [Bridge to Navigation]
│  ├─ undisplaySlide()     [Cleanup]
│  ├─ updateProgress()     [Display numbers]
│  ├─ initProgress()       [Initialize UI]
│  ├─ scrollSlide()        [Viewport]
│  └─ speak()              [Accessibility]
│
├─ Category 2: CONTROL (2)
│  ├─ hideMouseReset()     [Timer management]
│  └─ initHideMouse()      [Cursor control]
│
├─ Category 3: FEATURE PANELS (5)
│  ├─ help()               [? key]
│  ├─ tableOfContents()    [C key]     ← SHARED
│  ├─ toggleComments()     [C key]     ← CONFLICT
│  ├─ getSlideTitle()      [Utility]
│  └─ createTOCText()      [Utility]
│
├─ Category 4: MODE/VISUAL (5)
│  ├─ toggleMode()         [Core state]
│  ├─ toggleModeAndFullscreen() [Combined]
│  ├─ toggleFullscreen()   [Browser API]
│  ├─ toggleDarkMode()     [BOUNDARY BREACH]
│  └─ initDarkMode()       [Color initialization]
│
└─ Category 5: ANNOTATION (1)
   └─ toggleAnnotate()     [W key + Mouse]
```

---

## 🔗 Dependency Network Diagram

```
                          INPUT SYSTEM
                         (Phase 7)
                              ↓
                    ┌─────────┼─────────┐
                    ↓         ↓         ↓
               KEYBOARD    MOUSE      TIMER
               (keyDown)   (move)   (callback)
                 ↓           ↓          ↓
         ┌───────┼───────┐   │         │
         ↓       ↓       ↓   ↓         ↓
      Navigation Features  Input   slideTimer
         ↓         ↓       ↓          ↓
      (Phase 6)   (Phase 8) Control   ↓
         ↓         ↓          ↓        ↓
      nextSlide toggleFeatures hideMouseReset nextSlide
      previous  Panel State      ↓             ↓
      target    Dark Mode    initHideMouse makeCurrent
         ↓         ↓             ↓            ↓
         └─────────┴─────────────┴────────────┘
                   ↓
          makeCurrent() [BRIDGE]
                   ↓
          displaySlide() [GOD FUNCTION]
          ├─ updateProgress()
          ├─ initProgress()
          ├─ initIncrementals()
          ├─ speak()
          ├─ stopVideos()
          └─ [70+ DOM operations]
                   ↓
            DOM RENDERING
          ├─ classList changes
          ├─ style updates
          ├─ innerHTML
          └─ textContent
                   ↓
              VISUAL OUTPUT
```

---

##  Critical Coupling Points Map

```
┌─ Coupling 1: displaySlide() God Function ─────────────────────┐
│                                                                 │
│  Navigation (Phase 6)  Feature (Phase 8)  Accessibility       │
│        ↓                     ↓                  ↓              │
│   makeCurrent()     initIncrementals()      speak()           │
│        └─────────────────────┬──────────────────┘             │
│                              ↓                                │
│                     displaySlide()  [MIXES 5 CONCERNS]        │
│                        ├─ UI update                           │
│                        ├─ Feature init                        │
│                        ├─ Accessibility                       │
│                        ├─ Media (stopVideos)                  │
│                        └─ DOM manipulation (70+)             │
│                                                                │
│  Problem: Cannot extract any concern independently            │
│  Impact: Hard to test, hard to refactor, hard to decouple     │
└─────────────────────────────────────────────────────────────┘

┌─ Coupling 2: Mode Toggle Cascades ─────────────────────────┐
│                                                              │
│  toggleMode() sets slidemode = !slidemode                  │
│        ↓                                                     │
│  All features react implicitly:                             │
│  ├─ Annotation: canvas destroyed                           │
│  ├─ Help/TOC: modals closed                                │
│  ├─ Comments: panel visibility changes                     │
│  ├─ Dark Mode: rendering updates                           │
│  └─ Input: key interpretation changes                      │
│                                                              │
│  Problem: Side effects scattered across codebase            │
│  Impact: Mode toggle has cascading effects                  │
└──────────────────────────────────────────────────────────────┘

┌─ Coupling 3: Dark Mode → Second Window (BREACH) ─────────────┐
│                                                                │
│  Input (D key)                                               │
│        ↓                                                      │
│  toggleDarkMode()                                            │
│        ├─ hasDarkMode = !hasDarkMode  [Feature State]       │
│        ├─ initDarkMode()               [DOM Update]         │
│        └─ postMessage()                [BOUNDARY BREACH]    │
│                ↓                                              │
│          Second Window                                       │
│          (Different Process/Domain)                          │
│                                                                │
│  Problem: Feature communicates across system boundary        │
│  Risk: Other features may follow this pattern               │
│  Impact: Unpredictable sync behavior                         │
└─────────────────────────────────────────────────────────────┘

┌─ Coupling 4: C Key Routing Conflict ─────────────────────────┐
│                                                                │
│  Input (C key)                                               │
│        ↓                                                      │
│  keyDown()                                                   │
│        ├─ if (condition) toggleComments()                   │
│        └─ else tableOfContents()                            │
│                                                                │
│  Problem: Same key triggers two different features          │
│  Routing logic: Hidden in keyDown()                         │
│  Behavior: Implicit toggle or state-based decision          │
│  Impact: Cannot add 3rd feature easily                      │
└─────────────────────────────────────────────────────────────┘

┌─ Coupling 5: DOM Coupling (Heavy) ─────────────────────────────┐
│                                                                  │
│  UI Functions directly manipulate DOM:                          │
│  ├─ style.width: 114+ direct calls                            │
│  ├─ classList: 70+ direct calls                               │
│  ├─ getElementById: 12+ direct selectors                      │
│  ├─ innerHTML: 9+ direct insertions                           │
│  ├─ textContent: 18+ direct updates                           │
│  └─ Total: 314+ direct DOM operations                         │
│                                                                  │
│  Problem: Brittle to HTML structure changes                   │
│  Risk: Fragile selectors, hard to maintain                    │
│  Impact: Cannot test UI independently                         │
└──────────────────────────────────────────────────────────────┘
```

---

## 🎯 Entry Points Visualization

```
ENTRY 1: Navigation (Arrow Keys / Space)
┌─────────────────────────────────────────┐
│ User: Space / Right / Down              │
│ → keyDown('Space')                      │
│ → nextSlideOrElt()                      │
│ → nextSlide()                           │
│ → targetSlide(n)                        │
│ → makeCurrent(slide)                    │
│ → displaySlide(slide) [GOD FUNCTION]    │
│ ├─ updateProgress()                     │
│ ├─ initProgress()                       │
│ └─ UI UPDATED                           │
│                                         │
│ Result: Slide changed, progress updated │
└─────────────────────────────────────────┘

ENTRY 2: Feature Panel (C Key)
┌─────────────────────────────────────────┐
│ User: C key                             │
│ → keyDown('C')                          │
│ → ROUTING DECISION                      │
│   ├─ if (condition) toggleComments()    │
│   │  → commentsVisible = !visible       │
│   │  → classList.toggle('show')         │
│   │                                     │
│   └─ else tableOfContents()             │
│      ├─ getSlideTitle() × n slides      │
│      ├─ createTOCText()                 │
│      → Show TOC modal                   │
│                                         │
│ Result: Panel shown/hidden              │
│ Problem: C key conflict (shared)        │
└─────────────────────────────────────────┘

ENTRY 3: Dark Mode (D Key)
┌─────────────────────────────────────────┐
│ User: D key                             │
│ → keyDown('D')                          │
│ → toggleDarkMode()                      │
│ ├─ hasDarkMode = !hasDarkMode           │
│ ├─ initDarkMode()                       │
│ │  ├─ body.classList.toggle('dark')     │
│ │  └─ Canvas colors updated             │
│ │                                       │
│ └─ postMessage() to Window 2 [BREACH]   │
│                                         │
│ Result: Dark/light colors applied       │
│ Problem: Feature calls postMessage()    │
└─────────────────────────────────────────┘

ENTRY 4: Drawing Mode (W Key)
┌─────────────────────────────────────────┐
│ User: W key                             │
│ → keyDown('W')                          │
│ → toggleAnnotate()                      │
│ ├─ canvas = create/destroy element      │
│ ├─ canvasContext = 2D/null              │
│ └─ Mouse listeners attach               │
│                                         │
│ User: Mouse move/click (in annotation)  │
│ → canvasMouseMove()                     │
│ → drawing.stroke()                      │
│ → Canvas updated                        │
│                                         │
│ Result: Drawing mode on/off             │
│ Problem: Canvas destroyed on mode exit  │
└─────────────────────────────────────────┘

ENTRY 5: Mouse Auto-Hide (Movement)
┌─────────────────────────────────────────┐
│ User: Mouse move                        │
│ → recordMousePosition()                 │
│ → hideMouseReset()                      │
│ ├─ clearTimeout(hideMouseID)            │
│ └─ setTimeout(initHideMouse, 2000ms)    │
│                                         │
│ If no movement for 2s:                  │
│ → initHideMouse()                       │
│ → style.cursor = 'none'                 │
│                                         │
│ Result: Cursor auto-hidden              │
└─────────────────────────────────────────┘

ENTRY 6: Timer Auto-Advance (Progress)
┌─────────────────────────────────────────┐
│ slideTimer callback                     │
│ → nextSlide()                           │
│ → makeCurrent()                         │
│ → displaySlide()                        │
│ → updateProgress()                      │
│ ├─ progressElts.style.width = "%"       │
│ └─ slidenumElts.textContent = "n/m"     │
│                                         │
│ Result: Progress bar and numbers update │
└─────────────────────────────────────────┘
```

---

## ✅ Phase 9 Summary

```
Phase 9: Toolbar/UI Analysis
├─ 19 functions identified ✅
├─ 18 state variables mapped ✅
├─ 6 entry points documented ✅
├─ 5 critical couplings found ✅
├─ 314+ DOM operations analyzed ✅
└─ Boundary comments designed ✅

Key Finding: displaySlide() is GOD FUNCTION
Problem: Mixes Navigation + Features + UI + Accessibility
Impact: Cannot refactor individually
Solution (Phase 10): Extract into 4 separate concerns

Next Phase: Phase 10 — Refactoring and Decoupling
```

---

**This completes Phase 9 visual architecture mapping.**
