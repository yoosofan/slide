# Phase 4 — API / Interface Design

## Status

Phase 4 — API / Interface Design

This phase documents subsystem boundaries, state ownership,
dependencies, and future API boundaries before code extraction.

No functional code changes are introduced in this phase.

---

## 1. Navigation / Slide Engine

### State

- curslide
- numslides
- interactive
- slideCopy
- commentCopy

### Functions

- nextSlide
- previousSlide
- nextSlideOrElt
- previousSlideOrElt
- firstSlide
- lastSlide
- findSlide
- targetSlide
- displaySlide
- undisplaySlide
- makeCurrent
- hideSlide
- unhideSlide
- isStartOfSlide
- updateProgress
- numberSlides
- getSlideTitle
- scrollSlide

### Consumers

- Input System
- Toolbar / UI
- SSE Sync

### External dependencies

- DOM slide classes
- scrollIntoView
- Accessibility
- Automatic Slide Timer
- Session Clock

---

## 2. Input System

### State

- gesture
- noclick
- singleClickTimer
- mouseX
- mouseY
- hideMouseTime
- hideMouseID

### Functions

- keyDown
- mouseButtonClick
- doubleClick
- gestureStart
- gestureMove
- gestureEnd
- gestureCancel
- hideMouse
- hideMouseReset
- initHideMouse
- recordMousePosition

### Important architectural note

keyDown is currently a central dispatcher rather than an isolated subsystem.
It communicates with Navigation, SSE Sync, Second Window, Mode Toggle,
Dark Mode, Drawing, TOC, Comments, Timer, Accessibility and Help.

Therefore extraction of KeyboardController should use explicit dependencies
rather than moving keyDown as an independent self-contained manager.

---

## 3. Second Window Contract

### State

- secondwindow
- firstwindow
- commentsWereVisible

### Functions

- openSecondWindow
- message
- checkIfSecondWindow
- beforeUnload

### Dependencies

- window.open
- message event
- Mode Toggle
- Session Clock

---

## 4. SSE Sync Contract

### State

- syncmode
- syncURL
- eventsource

### Functions

- warnSyncMode
- errorSyncMode
- tryToggleSync
- syncSlide
- syncHandler

### Dependencies

- EventSource / network
- Navigation / Slide Engine

---

## 5. Mode Toggle State Machine

### State

- slidemode
- switchInProgress
- fullmode
- switchFullscreen

### Functions

- toggleMode
- finishToggleMode
- toggleModeAndFullscreen
- toggleFullscreen
- fullscreenChanged

### Dependencies

- Fullscreen API
- Second Window handshake

### Architectural note

toggleMode is a sensitive state machine because it also participates
in the second-window handshake.

## 6. Session Clock

## 7. Automatic Slide Timer

## 8. Feature Managers

### 8.1 Incrementals
### 8.2 Comments
### 8.3 TOC
### 8.4 Help
### 8.5 Dark Mode
### 8.6 Media
### 8.7 Drawing

## 9. Toolbar / UI

## 10. New Features Boundary

## 11. Cross-cutting / Global State

## 12. Accessibility Contract

## 13. URL / Hash Contract

---

# State Ownership Matrix

| Subsystem | State | Owner Candidate | Readers | Writers | External Effects |
|---|---|---|---|---|---|
| Navigation | curslide | Navigation | Input, Toolbar, Sync | Navigation | DOM |
| Input | gesture | Input | Mouse handlers | Input | Browser events |
| Second Window | secondwindow | Second Window | Clock, UI | Second Window | window.open/postMessage |
| SSE Sync | syncmode | Sync | Input | Sync | EventSource |
| Mode Toggle | slidemode | Mode Toggle | Input, UI | Mode Toggle | Fullscreen API |
| Session Clock | startTime | Session Clock | UI, Second Window | Clock | setInterval |
| Auto Timer | slideTimer | Slide Timer | Navigation/Input | Timer | setTimeout |



| Variable | Owner Subsystem | Writers | Readers (other) |
|---|---|---|---|
| curslide | Navigation ⚠️cross | doubleClick, makeCurrent, message | createTOCText, displaySlide, finishToggleMode, initIncrementals, nextSlide, nextSlideOrElt, previousSlide, previousSlideOrElt, rewindVideos, scrollSlide, speak, stopVideos, syncSlide, tableOfContents, toggleAnnotate, toggleMode, undisplaySlide, updateProgress |
| slidemode | Mode Toggle | toggleMode | (read in ~25 functions across nearly every subsystem — expected, it's a global mode flag) |
| switchInProgress | Mode Toggle | finishToggleMode, toggleMode | windowResize |
| incrementals | Feature Managers (Incrementals) | initIncrementals | displaySlide, finishToggleMode, nextSlideOrElt, previousSlideOrElt, scrollSlide, speak, timeToMillisec |
| gesture | Input | (init only) | gestureCancel, gestureEnd, gestureMove, gestureStart |
| numslides | Navigation | numberSlides | updateProgress |
| stylesToLoad | Mode Toggle ⚠️cross | finishToggleMode, load, toggleMedia | - |
| limit | Mode Toggle | finishToggleMode, toggleMode | - |
| interactive | Navigation ⚠️cross | checkURL | checkIfSecondWindow, cloneNodeClean, createHelpText, initProgress, initialize |
| fullmode | Mode Toggle ⚠️cross | checkURL | initialize |
| progressElts | Navigation | numberSlides | initProgress, updateProgress |
| slidenumElts | Navigation | numberSlides | initProgress, updateProgress |
| numslidesElts | Navigation | numberSlides | initProgress |
| liveregion | Accessibility | initLiveRegion | hideSlide, initIncrementals, speak, speakIt, toggleMode, unhideSlide |
| slideCopy | ⚠️ DEAD CODE | (init only) | never used anywhere else |
| commentCopy | ⚠️ DEAD CODE | (init only) | never used anywhere else |
| lastSpoken | Accessibility | speak | - |
| savedContent | Accessibility | initLiveRegion | speak |
| noclick | Input ⚠️cross | checkOptions | createHelpText, doubleClick, gestureEnd, mouseButtonClick, toggleAnnotate |
| hideMouseTime | Input ⚠️cross | checkOptions | hideMouseReset, initHideMouse |
| helptext | Feature Managers (Help) | createHelpText | fullscreenChanged, help, toggleFullscreen |
| toctext | Feature Managers (TOC) | createTOCText | fullscreenChanged, getSlideTitle, keyDown, tableOfContents, toggleMode |
| tocItems | Feature Managers (TOC) | (init only) | createTOCText, tableOfContents |
| hideMouseID | Input | hideMouse, hideMouseReset | - |
| singleClickTimer | Input | doubleClick, mouseButtonClick | - |
| secondwindow | Second Window | openSecondWindow | (read across ~19 functions — expected, contract's purpose) |
| firstwindow | Second Window | checkIfSecondWindow | (read across ~22 functions — expected) |
| syncmode | Second Window ⚠️cross / SSE Sync | message, tryToggleSync | commentButtonClick, createHelpText, darkModeButtonClick, doubleClick, gestureEnd, keyDown, mouseButtonClick, playButtonClick, secondWindowButtonClick, syncHandler |
| syncURL | URL/Hash ⚠️cross | checkURL | createHelpText, keyDown, tryToggleSync |
| eventsource | SSE Sync | tryToggleSync | - |
| startTime | Session Clock ⚠️cross | initClocks, message, pauseTime, resetTime | updateClocks |
| pauseStartTime | Session Clock ⚠️cross | message, pauseTime | updateClocks |
| clockElts | Session Clock | initClocks | updateClocks |
| fullclockElts | Session Clock | initClocks | updateClocks |
| realHoursElts | Session Clock | initClocks | updateClocks |
| realMinutesElts | Session Clock | initClocks | updateClocks |
| realSecondsElts | Session Clock | initClocks | updateClocks |
| usedHoursElts | Session Clock | initClocks | updateClocks |
| usedMinutesElts | Session Clock | initClocks | updateClocks |
| usedSecondsElts | Session Clock | initClocks | updateClocks |
| leftHoursElts | Session Clock | initClocks | updateClocks |
| leftMinutesElts | Session Clock | initClocks | updateClocks |
| leftSecondsElts | Session Clock | initClocks | updateClocks |
| clockTimer | Session Clock | initClocks | - |
| duration | Session Clock ⚠️cross | addMinute, checkOptions, initClocks, message, subtractMinute | requestClocksUpdate, updateClocks |
| warnTime | Session Clock ⚠️cross | checkOptions | updateClocks |
| language | Initialization | initLanguage | _, checkOptions, initialize, speakIt |
| switchFullscreen | Mode Toggle | fullscreenChanged, toggleFullscreen | - |
| hasDarkMode | Feature Managers (Dark Mode) | initDarkMode | addUI, beforeUnload, createHelpText, initialize, toggleDarkMode |
| incrementalsBehavior | Feature Managers (Incrementals) ⚠️cross | checkOptions | initIncrementals, previousSlideOrElt |
| slideTimer | Automatic Slide Timer ⚠️cross | displaySlide, nextSlideOrElt | help, pauseAutomaticSlides, tableOfContents, toggleMode |
| slideTiming | Automatic Slide Timer ⚠️cross | checkOptions | createHelpText, displaySlide, nextSlideOrElt |
| slideTimerPaused | Automatic Slide Timer | pauseAutomaticSlides, unpauseAutomaticSlides | displaySlide, keyDown, nextSlideOrElt |
| loopSlideShow | Automatic Slide Timer ⚠️cross | checkOptions | nextSlide |
| scale | Navigation (Layout) | scaleBody | finishToggleMode, scaleFontIfNeeded, scaleImagesIfNeeded, scrollSlide, shrinkWindow, toggleMedia, toggleMode |
| canvas | Feature Managers (Drawing) ⚠️cross | toggleAnnotate, toggleMode | pauseAutomaticSlides |
| canvasContext | Feature Managers (Drawing) | toggleAnnotate | - |
| canvasX | Feature Managers (Drawing) | toggleAnnotate | - |
| canvasY | Feature Managers (Drawing) | toggleAnnotate | - |
| hoverOverlay | Navigation | showURL | - |
| mouseX | Input | recordMousePosition | showURL |
| mouseY | Input | recordMousePosition | showURL |
| commentsVisible | Feature Managers (Comments) | toggleComments | hashchange, message, toggleMode |
| commentsWereVisible | Second Window ⚠️cross | message | - |
| commentsDefault | Feature Managers (Comments) ⚠️cross | checkOptions, checkURL | initialize |
| visibleSlide | Feature Managers (Comments) | toggleComments | - |
| forceClocks | Session Clock ⚠️cross | addMinute, message, pauseTime, resetTime, subtractMinute | - |
| clocksUpdateRequested | Session Clock | requestClocksUpdate | - |
| useApplication | Mode Toggle ⚠️cross | checkOptions | checkIfSecondWindow, toggleMode |