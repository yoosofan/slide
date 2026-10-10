# Phase 7: Input System Analysis

**فایل:** docs/phase7-input-analysis.md  
**وضعیت:**  Ready for Documentation  

---

## Scope

Analysis and documentation of the existing input/event routing system.

**No refactoring, extraction, or code changes.**

Only document:
- How user/browser events enter the system
- How guard conditions affect routing
- Which existing functions are reached by each input path

---

## Core Input Handlers (12 Functions)

### Keyboard Input
1. **keyDown()** [Line 1998]
   - Main keyboard event dispatcher
   - Routes key events to navigation, mode toggle, features, and accessibility

### Mouse Input
2. **mouseButtonClick()** [Line 2707]
   - Single-click handler with 300ms delay for double-click detection
   - Sets singleClickTimer to call nextSlideOrElt() if not cancelled

3. **doubleClick()** [Line 2845]
   - Double-click handler
   - Cancels singleClickTimer and calls toggleModeAndFullscreen()

4. **recordMousePosition()** [Line 3527]
   - Tracks mouseX, mouseY on mousemove
   - Resets hideMouseTimer

5. **hideMouse()** [Location: search in code]
   - Hides mouse cursor
   - Called after hideMouseTime threshold

6. **hideMouseReset()** [Line 1294]
   - Resets mouse visibility timer
   - Schedules hideMouse() callback

7. **initHideMouse()** [Location: search in code]
   - Initializes mouse hide behavior
   - Called during initialization

### Touch / Gesture Input
8. **gestureStart()** [Line 2754]
   - Initializes gesture tracking
   - Records gesture.on, gesture.touches, gesture.startX/Y

9. **gestureMove()** [Line 2767]
   - Updates gesture position during touch
   - Records gesture.lastX/Y, calculates delta

10. **gestureEnd()** [Line 2787]
    - Evaluates gesture type and triggers action
    - Handles 3-finger, 2-finger, 1-finger swipe
    - Calls navigation or mode-toggle functions

11. **gestureCancel()** [Line 2834]
    - Cancels gesture in progress
    - Sets gesture.on = false

### Input Filtering
12. **ignoreEvent()** [Location: search in code]
    - Guards against duplicate or invalid events
    - Checks noclick flag, event timing, modifier keys

---

## Analysis Areas

### 1. Event Listener → Handler Mapping

**Keyboard:**
```
Document/Window
└─ addEventListener('keydown', keyDown)
   └─ Handler: keyDown(event)
      └─ Routes to: Navigation, Mode Toggle, Features, Accessibility
```

**Mouse:**
```
Document/Window
├─ addEventListener('click', mouseButtonClick)
│  └─ Handler: mouseButtonClick(event)
│     └─ if (pass guards) → singleClickTimer (300ms delay)
│        └─ Routes to: nextSlideOrElt()
│
├─ addEventListener('dblclick', doubleClick)
│  └─ Handler: doubleClick(event)
│     └─ clearTimeout(singleClickTimer)
│     └─ Routes to: toggleModeAndFullscreen()
│
└─ addEventListener('mousemove', recordMousePosition)
   └─ Handler: recordMousePosition(event)
      ├─ Updates: mouseX, mouseY
      └─ Resets: hideMouseTimer
```

**Touch/Gesture:**
```
Document/Window
├─ addEventListener('touchstart', gestureStart)
│  └─ Handler: gestureStart(event)
│     └─ Initialize gesture object
│
├─ addEventListener('touchmove', gestureMove)
│  └─ Handler: gestureMove(event)
│     └─ Update gesture position
│
├─ addEventListener('touchend', gestureEnd)
│  └─ Handler: gestureEnd(event)
│     └─ Evaluate gesture and route
│
└─ addEventListener('touchcancel', gestureCancel)
   └─ Handler: gestureCancel(event)
      └─ Cancel gesture state
```

---

### 2. Handler → Guard → Target Function Mapping

#### Keyboard Flow
```
keyDown(event)
├─ GUARD: if (syncmode) → warnSyncMode() [for most keys]
│
├─ KEY: Space/Right/Down
│  └─ CONDITION: if (!slidemode || !syncmode)
│  └─ TARGET: nextSlideOrElt()
│
├─ KEY: Left/Up
│  └─ CONDITION: if (!slidemode || !syncmode)
│  └─ TARGET: previousSlideOrElt()
│
├─ KEY: PageDown
│  └─ CONDITION: if (!slidemode || !syncmode)
│  └─ TARGET: nextSlide()
│
├─ KEY: PageUp
│  └─ CONDITION: if (!slidemode || !syncmode)
│  └─ TARGET: previousSlide()
│
├─ KEY: Home
│  └─ CONDITION: if (!slidemode || !syncmode)
│  └─ TARGET: firstSlide()
│
├─ KEY: End
│  └─ CONDITION: if (!slidemode || !syncmode)
│  └─ TARGET: lastSlide()
│
├─ KEY: A (Alt held)
│  └─ CONDITION: if (slidemode && !syncmode)
│  └─ TARGET: toggleModeAndFullscreen() OR postMessage(window2)
│
├─ KEY: F / F1
│  └─ CONDITION: if (slidemode && !syncmode)
│  └─ TARGET: toggleFullscreen()
│
├─ KEY: Escape
│  └─ CONDITION: if (slidemode && !syncmode)
│  └─ TARGET: toggleModeAndFullscreen()
│
├─ KEY: 2
│  └─ CONDITION: if (slidemode && !syncmode && !secondwindow)
│  └─ TARGET: openSecondWindow()
│
├─ KEY: ?
│  └─ TARGET: help(event)
│
├─ KEY: C
│  └─ TARGET: tableOfContents() OR toggleComments()
│
├─ KEY: P / MediaPlay
│  └─ TARGET: pause/resume slideTimer
│
├─ KEY: S
│  └─ TARGET: tryToggleSync()
│
├─ KEY: D
│  └─ CONDITION: if (slidemode)
│  └─ TARGET: toggleDarkMode()
│
├─ KEY: W
│  └─ CONDITION: if (slidemode && !syncmode)
│  └─ TARGET: toggleAnnotate()
│
└─ KEY: N
   └─ CONDITION: if (slidemode)
   └─ TARGET: speak(TOGGLE)
```

#### Mouse Single-Click Flow
```
click(e)
├─ GUARD: ignoreEvent(e)
│  ├─ if (noclick > 0) return
│  ├─ if (e.button != 0) return  [not left button]
│  ├─ if (e.detail > 1) return   [already handled as double-click]
│  ├─ if (e.altKey || e.ctrlKey || e.metaKey || e.shiftKey) return
│  └─ if (syncmode) return
│
└─ ACTION:
   └─ singleClickTimer = setTimeout(() => {
      ├─ if (slidemode) nextSlideOrElt()
      └─ else [no action]
   }, 300ms)  [delay for double-click detection]
```

#### Mouse Double-Click Flow
```
dblclick(e)
├─ GUARD: ignoreEvent(e)
│
├─ ACTION:
│  ├─ clearTimeout(singleClickTimer)  [cancel pending single-click]
│  │
│  └─ if (slidemode && !syncmode) {
│     └─ toggleModeAndFullscreen()
│  }
```

#### Mouse Position & Hide
```
mousemove(e)
├─ recordMousePosition(e)
│  ├─ mouseX = e.clientX
│  ├─ mouseY = e.clientY
│  │
│  └─ if (hideMouseTimer active) {
│     ├─ clearTimeout(hideMouseID)
│     └─ hideMouseReset()  [restart timer]
│  }
```

#### Touch/Gesture Flow
```
gestureStart(e)
├─ gesture.on = true
├─ gesture.touches = e.touches.length
├─ gesture.startX = first touch X
└─ gesture.startY = first touch Y

gestureMove(e)
├─ gesture.lastX = current touch X
├─ gesture.lastY = current touch Y
└─ [calculate movement]

gestureEnd(e)
├─ if (!gesture.on) return
│
├─ GUARD: if (syncmode) warnSyncMode()
│
├─ 3-finger gesture (gesture.touches > 2):
│  └─ TARGET: toggleModeAndFullscreen()
│
├─ 2-finger gesture (gesture.touches == 2):
│  └─ [current behavior undefined in analyzed code]
│
└─ 1-finger swipe:
   ├─ MEASURE: horizontal delta = gesture.lastX - gesture.startX
   ├─ THRESHOLD: [extract from actual code analysis]
   │
   ├─ if (delta > threshold, swipeRight):
   │  └─ TARGET: previousSlide()
   │
   └─ if (delta < -threshold, swipeLeft):
      └─ TARGET: nextSlide() OR nextSlideOrElt()

gestureCancel(e)
└─ gesture.on = false
```

---

### 3. Guard Conditions & State Dependencies

#### Primary Guard: syncmode
```
syncmode = true (Sync mode active)
├─ EFFECT: Blocks most input handlers
├─ EXCEPTION: Some keys allow input but call warnSyncMode()
└─ PURPOSE: Prevent state divergence between synced windows
```

#### Secondary Guard: slidemode
```
slidemode = true (Slide presentation mode active)
├─ EFFECT: Routes input to Navigation and Mode Toggle handlers
├─ FALSE: Routes input to Feature handlers or no action
└─ PURPOSE: Different input interpretation based on mode
```

#### Tertiary Guard: noclick
```
noclick counter > 0 (Click prevention active)
├─ EFFECT: mouseButtonClick() returns early
├─ USE CASE: Prevents click during drag, selection, or transition
└─ PURPOSE: Suppress unintended clicks
```

#### Modifier Keys Guard
```
if (e.altKey || e.ctrlKey || e.metaKey || e.shiftKey)
├─ EFFECT: Most mouse clicks ignored
├─ EXCEPTION: Alt + A may have special meaning
└─ PURPOSE: Avoid browser shortcut conflicts
```

---

### 4. Timing Dependencies

#### Single-Click vs Double-Click
```
Timing Dependency: 300ms

User clicks
├─ mouseButtonClick() called
├─ singleClickTimer = setTimeout(nextSlideOrElt, 300ms)
│
├─ if user clicks again within 300ms:
│  ├─ doubleClick() called
│  ├─ clearTimeout(singleClickTimer)  [cancel pending single-click]
│  └─ toggleModeAndFullscreen() called
│  └─ RESULT: Double-click behavior
│
└─ if user does NOT click within 300ms:
   └─ singleClickTimer callback fires
   └─ RESULT: Single-click behavior
```

**Temporal Coupling:** Single-click and double-click handlers share singleClickTimer state and must coordinate via setTimeout/clearTimeout.

#### Mouse Hide Timer
```
Timing Dependency: hideMouseTime threshold (~2000ms)

User moves mouse
├─ recordMousePosition() called
├─ hideMouseTimer scheduled
│
├─ if user moves mouse again within hideMouseTime:
│  ├─ clearTimeout(hideMouseID)
│  ├─ hideMouseReset() schedules new timer
│  └─ RESULT: Mouse stays visible
│
└─ if user does NOT move mouse within hideMouseTime:
   └─ hideMouse() callback fires
   └─ RESULT: Cursor hidden
```

**Temporal Coupling:** hideMouseTimer and hideMouseReset() must coordinate via setTimeout/clearTimeout.

---

### 5. Cross-System Dependencies

```
Input System
├─ → Navigation System (via keyDown, mouseClick, gestureEnd)
│  ├─ nextSlide(), previousSlide(), firstSlide(), lastSlide()
│  ├─ nextSlideOrElt(), previousSlideOrElt(), targetSlide()
│  └─ makeCurrent() [indirectly]
│
├─ → Mode Toggle System (via keyDown, mouseClick, gesture)
│  ├─ toggleMode(), finishToggleMode()
│  ├─ toggleFullscreen(), toggleModeAndFullscreen()
│  └─ slidemode state mutation
│
├─ → Feature Managers (via keyDown)
│  ├─ toggleDarkMode(), toggleAnnotate()
│  ├─ tableOfContents(), toggleComments()
│  └─ help(), speak()
│
├─ → SSE Sync System (via keyDown)
│  ├─ tryToggleSync()
│  └─ syncmode guard on all handlers
│
├─ → Accessibility System (via keyDown)
│  ├─ speak() [via 'N' key]
│  └─ live region announcements
│
└─ → Second Window / Communication (via keyDown)
   ├─ openSecondWindow() [via '2' key]
   └─ postMessage() [for mode toggle in sync]
```

---

### 6. Secondary & Additional Input Paths

**Note:** Event listeners exist beyond the 12 core handlers for:
- Toolbar button clicks (DOM elements)
- UI widget interactions
- Legacy support or multi-window contexts

These are documented separately as **Secondary Input Paths** and do NOT replace the core Input System analysis.

---

## Input State Variables

```
Input System State (Phase 5):

let gesture = {};           // Touch/gesture tracking
let noclick = 0;            // Click prevention counter
let hideMouseTime = null;   // Mouse hide delay reference
let hideMouseID = null;     // Mouse hide timer ID
let singleClickTimer = null;// Single-click timer (vs double-click)
let mouseX = 0;             // Mouse X position
let mouseY = 0;             // Mouse Y position
```

---

## Architecture Boundary


### What Phase 7 Only Does

- ✅ Document existing event → handler flow
- ✅ Document guard conditions and state dependencies
- ✅ Document timing dependencies (temporal coupling)
- ✅ Document cross-system dependencies
- ✅ Clarify how user interactions reach target functions
- ✅ Identify candidates for Phase 8-11 refactoring

---

## Relationship to Previous Phases

```
Phase 6: Navigation / Slide Engine
├─ Documents: Functions that perform navigation
├─ Functions: displaySlide, makeCurrent, nextSlide, etc.
└─ Output: Navigation subsystem architecture

Phase 7: Input System
├─ Documents: Event routing that triggers navigation
├─ Functions: keyDown, mouseClick, gestureEnd, etc.
└─ Output: Input subsystem architecture + dependencies

Phase 8+: Refactoring (to be planned)
├─ Separate input handler consolidation
├─ Timing dependency resolution
├─ Guard condition refactoring
└─ Cross-system decoupling
```

---

## Complete Input → Target Flow

```
User Action / Browser Event
    ↓
Event Listener (addEventListener)
    ↓
Input Handler (12 core functions)
    ├─ Guard Evaluation (syncmode, slidemode, noclick, modifiers)
    ├─ State Mutation (mouseX/Y, gesture, timer state)
    └─ Routing Decision
    ↓
Target Function Call
    ├─ Navigation Functions (nextSlide, etc.)
    ├─ Mode Toggle Functions (toggleMode, etc.)
    ├─ Feature Functions (toggleDarkMode, etc.)
    ├─ Accessibility Functions (speak, etc.)
    └─ Sync Functions (tryToggleSync, etc.)
    ↓
Navigation / Mode / Feature / Accessibility / Sync System
```

---

## Phase 7 Deliverables

### Document Structure
```
docs/phase7-input-analysis.md
├─ Scope & Architecture Boundary
├─ Core Input Handlers (12 functions with line numbers)
├─ Event Listener → Handler Mapping
├─ Handler → Guard → Target Function Mapping (for all keys/gestures)
├─ Guard Conditions & State Dependencies
├─ Timing Dependencies (singleClickTimer, hideMouseTimer)
├─ Cross-System Dependencies
├─ Secondary Input Paths (documented separately)
├─ Phase 6 → Phase 7 Relationship
├─ Complete Flow Diagram (User → Handler → Target)
└─ Phase 8-11 Refactoring Candidates
```

### Code Boundary (in b6_plus_plus.js)
```javascript
/* ===== Input System (Core - 12 functions) ===== */
// Event listeners and handlers for keyboard, mouse, touch input
// Guard conditions: syncmode, slidemode, noclick, modifier keys
// Timing dependencies: singleClickTimer (300ms), hideMouseTimer (~2000ms)
// Routes to: Navigation, Mode Toggle, Features, Accessibility, Sync systems
// See: docs/phase7-input-analysis.md for complete analysis

// Keyboard
function keyDown(event) { ... }

// Mouse
function mouseButtonClick(e) { ... }
function doubleClick(e) { ... }
function recordMousePosition(e) { ... }
function hideMouse() { ... }
function hideMouseReset() { ... }
function initHideMouse() { ... }

// Touch/Gesture
function gestureStart(e) { ... }
function gestureMove(e) { ... }
function gestureEnd(e) { ... }
function gestureCancel(e) { ... }

// Input Filtering
function ignoreEvent(e) { ... }
```

---
