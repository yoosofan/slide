# Phase 8: Feature Managers

**فایل:** docs/phase8-feature-managers.md  
**وضعیت:** ✅ Analysis and Documentation Only  

---

## Scope

Analysis and documentation of independent feature managers in b6_plus_plus.

**No refactoring, extraction, or code changes in this phase.**

Feature Managers provide additional presentation capabilities (incrementals, comments, TOC, help, dark mode, annotation) layered on top of the Navigation and Mode Toggle subsystems.

---

## ۶ Feature Managers (Core Features)

### 1. Incrementals (Progressive Disclosure)

**Purpose:** Display slide content progressively, revealing one section at a time within a single slide.

**State Variables:**
```javascript
let incrementals = [];              // Array of increment elements
let incrementalsBehavior = "click";  // Behavior: "click" or "auto"
```

**Core Functions:**
- **initIncrementals()** [Line 887]
  - Initializes incremental disclosure for current slide
  - Scans DOM for b6increment elements
  - Sets up visibility state
  
- **nextSlideOrElt()** [Line 2514]
  - Navigation function: increment-aware next
  - Calls incrementals.cur++
  - If more incrementals, scroll and display
  - Else: nextSlide() to next slide
  
- **previousSlideOrElt()** [Line 2592]
  - Navigation function: increment-aware previous
  - Calls incrementals.cur--
  - If previous incremental exists, display
  - Else: previousSlide() to previous slide
  
- **displaySlide()** [Line 1496]
  - Calls initIncrementals() when showing new slide
  - Resets incremental counter

**State Dependencies:**
```
Input System (Keyboard)
    ↓
nextSlideOrElt / previousSlideOrElt
    ↓
incrementals.cur state mutation
    ↓
displaySlide / scrollSlide
    ↓
UI visibility + Accessibility (speak)
```

**Cross-System Dependencies:**
- ✅ Input System: Space/Arrow keys trigger
- ✅ Navigation System: Uses nextSlide/previousSlide fallback
- ✅ Accessibility: Speaks each incremental
- ✅ UI: DOM classList changes

**Coupling Points:**
- Tight: displaySlide() directly calls initIncrementals()
- Tight: nextSlideOrElt() directly mutates incrementals.cur
- Moderate: Keyboard input hardwired to increment behavior

---

### 2. Comments / Speaker Notes

**Purpose:** Display speaker notes/comments associated with each slide.

**State Variables:**
```javascript
let commentsVisible = false;     // Comments panel visible?
let commentsDefault = true;      // Show by default?
let visibleSlide = null;         // Currently tracked slide
```

**Core Functions:**
- **toggleComments()** [Line 3590]
  - Toggle comments panel visibility
  - Calls trackVisibleSlides()
  
- **trackVisibleSlides()** [Line 3643]
  - Monitor which slide is in viewport
  - Updates visibleSlide state
  - Updates comments display accordingly

- **displaySlide()** [Line 1496]
  - Indirect: If commentsVisible, update displayed comments

**State Dependencies:**
```
Input System (C key)
    ↓
toggleComments()
    ↓
commentsVisible state mutation
    ↓
trackVisibleSlides()
    ↓
DOM update (comments panel)
```

**Cross-System Dependencies:**
- ✅ Input System: C key triggers toggle
- ✅ Navigation System: displaySlide() indirectly updates comments
- ✅ Accessibility: Comments can be read aloud
- ✅ UI: DOM manipulation for comments panel

**Coupling Points:**
- Moderate: toggleComments() called via keyDown()
- Loose: Comments display independent of main navigation
- Moderate: trackVisibleSlides() uses DOM methods

---

### 3. Table of Contents (TOC)

**Purpose:** Display table of contents showing all slides or sections.

**State Variables:**
```javascript
let toctext = null;    // TOC text content
let tocItems = [];     // Array of TOC entries
```

**Core Functions:**
- **tableOfContents()** [Line 1788]
  - Main TOC display function
  - Shows/hides TOC modal or view
  
- **getSlideTitle()** [Line 1713]
  - Extract title from slide element
  - Used to populate TOC
  
- **createTOCText()** [Line 1729]
  - Build TOC text from all slides
  - Format and structure TOC entries

**State Dependencies:**
```
Input System (C key)
    ↓
keyDown() routes to tableOfContents()
    ↓
toctext / tocItems state built
    ↓
DOM update (TOC display)
    ↓
Optional: targetSlide() if TOC item clicked
```

**Cross-System Dependencies:**
- ✅ Input System: C key (same as toggleComments)
- ✅ Navigation System: Can call targetSlide() from TOC click
- ✅ UI: DOM modal/panel display

**Coupling Points:**
- Moderate: Shares C key with toggleComments()
- Moderate: Can trigger targetSlide() navigation
- Loose: TOC content independent of other features

---

### 4. Help

**Purpose:** Display keyboard shortcuts and usage help.

**State Variables:**
```javascript
let helptext = null;   // Help text content
```

**Core Functions:**
- **help()** [Line 1702]
  - Main help display function
  - Shows keyboard shortcuts
  - Displays usage information

**State Dependencies:**
```
Input System (? key)
    ↓
keyDown() routes to help()
    ↓
helptext displayed
    ↓
DOM update (help modal/overlay)
```

**Cross-System Dependencies:**
- ✅ Input System: ? key triggers
- ✅ UI: DOM modal/overlay display

**Coupling Points:**
- Loose: Independent feature
- Simple: Minimal state management
- Minimal: No interaction with other features

---

### 5. Dark Mode

**Purpose:** Toggle dark/light color scheme for slides and UI.

**State Variables:**
```javascript
let hasDarkMode = false;  // Dark mode currently active?
```

**Core Functions:**
- **toggleDarkMode()** [Line 2429]
  - Toggle dark mode on/off
  - Updates document.body classList
  - Calls initDarkMode() or resetColorMode()
  
- **initDarkMode()** [Line 3254]
  - Initialize dark mode styling
  - Apply CSS class to body
  - Update colors for canvas, UI elements

**State Dependencies:**
```
Input System (D key)
    ↓
keyDown() routes to toggleDarkMode()
    ↓
hasDarkMode state mutation
    ↓
classList changes (document.body)
    ↓
Optional: postMessage() to Second Window
    ↓
CSS styling applied (dark colors)
```

**Cross-System Dependencies:**
- ✅ Input System: D key triggers
- ✅ Mode Toggle: Affects visibility of mode-specific colors
- ✅ Second Window: Posts color change message
- ✅ UI: CSS classes and color state

**Coupling Points:**
- Moderate: Uses document.body.classList (global)
- Moderate: Posts to Second Window for sync
- Loose: Color state independent of other features
- Tight: Hardwired to keyboard input (D key)

---

### 6. Annotation / Drawing

**Purpose:** Allow freehand drawing/annotations on slides in presentation mode.

**State Variables:**
```javascript
let canvas = null;          // Canvas HTML element
let canvasContext = null;   // Canvas 2D context
let canvasX = null;         // Canvas X position
let canvasY = null;         // Canvas Y position
```

**Core Functions:**
- **toggleAnnotate()** [Line 1947]
  - Toggle annotation mode on/off
  - Creates/destroys canvas overlay
  - Initializes canvas drawing context
  
- **[Canvas event handlers]** (need to search)
  - canvasKeyDown() → Handle Escape to exit annotation
  - canvasMouseMove() → Track mouse and draw strokes
  - canvasMouseUp() → End drawing stroke

**State Dependencies:**
```
Input System (W key)
    ↓
keyDown() routes to toggleAnnotate()
    ↓
canvas element created/destroyed
    ↓
canvasX / canvasY position tracked
    ↓
Mouse Input (mousemove, mousedown, mouseup)
    ↓
Drawing strokes rendered on canvas
    ↓
Mode Toggle: Canvas hidden when exiting slide mode
```

**Cross-System Dependencies:**
- ✅ Input System: W key triggers toggle
- ✅ Mouse Input: mousemove/click for drawing
- ✅ Mode Toggle: Canvas disabled when exiting slide mode
- ✅ UI: Canvas overlay on top of slides

**Coupling Points:**
- Moderate: Uses keyboard input (W key)
- Moderate: Uses mouse coordinates and events
- Tight: Mode toggle can destroy canvas state
- Tight: Canvas context stored as DOM reference

---

## Feature → Input Mapping

```
Input System (Keyboard)
├─ Space/Right/Down → nextSlideOrElt() [Incrementals aware]
├─ Left/Up → previousSlideOrElt() [Incrementals aware]
├─ C key → tableOfContents() OR toggleComments()
├─ ? key → help()
├─ D key → toggleDarkMode()
└─ W key → toggleAnnotate()

Input System (Mouse)
└─ Canvas area → Drawing strokes [if annotation mode]
```

---

## Feature → State Mutation Mapping

```
Feature          | State Var              | Type    | Mutated By
─────────────────┼────────────────────────┼─────────┼──────────────────
Incrementals     | incrementals.cur       | Direct  | nextSlideOrElt()
Incrementals     | incrementalsBehavior   | Config  | Setup only
Comments         | commentsVisible        | Direct  | toggleComments()
Comments         | visibleSlide           | Read    | trackVisibleSlides()
TOC              | toctext                | Built   | createTOCText()
TOC              | tocItems               | Built   | tableOfContents()
Help             | helptext               | Read    | help()
Dark Mode        | hasDarkMode            | Direct  | toggleDarkMode()
Annotation       | canvas                 | Ref     | toggleAnnotate()
Annotation       | canvasX / canvasY      | Track   | canvasMouseMove()
```

---

## Feature → Output Mapping

```
Feature          | DOM Changes           | State Changes     | API Calls
─────────────────┼───────────────────────┼───────────────────┼────────────────
Incrementals     | classList (b6show)    | incrementals.cur  | speak()
Comments         | Panel visibility      | commentsVisible   | trackVisibleSlides()
TOC              | Modal/panel show      | toctext, tocItems | targetSlide()
Help             | Modal/panel show      | helptext read     | None
Dark Mode        | body.classList        | hasDarkMode       | postMessage()
Annotation       | canvas.drawImage()    | canvas ref        | Mouse events
```

---

## Cross-Feature Coupling

### Incrementals ↔ Comments

```
Risk: incrementals.cur state affects which comments are shown
Mitigation: trackVisibleSlides() checks visible slide independently
Impact: Tight coupling if comments need incremental awareness
```

### Dark Mode ↔ Annotation

```
Risk: Canvas drawing colors depend on dark mode state
Mitigation: Canvas colors set dynamically based on hasDarkMode
Impact: Moderate coupling - colors must sync
```

### All Features ↔ Mode Toggle

```
Risk: Slide mode changes may reset feature state
Examples:
  - Annotation canvas destroyed on mode exit
  - TOC/Help modals closed on mode exit
  - Comments hidden on mode exit
Mitigation: toggleMode() explicitly handles cleanup
Impact: Moderate - all features affected by mode toggle
```

### All Features ↔ Input System

```
Tight coupling: All features triggered by keyboard input (C, D, W, ?)
Possible consolidation in Phase 8-9: Extract input routing to feature dispatchers
```

---

## Dependencies Between Phases

### Phase 5 → Phase 8
```
Phase 5 defines:
  incrementals, commentsVisible, commentsDefault, visibleSlide,
  toctext, tocItems, helptext, hasDarkMode, canvas, canvasContext, canvasX, canvasY

Phase 8 uses:
  These 12 state variables as Feature Manager state
```

### Phase 6 → Phase 8
```
Phase 6 defines:
  Navigation subsystem (displaySlide, makeCurrent, etc.)

Phase 8 depends on:
  displaySlide() for incremental initialization
  Navigation functions for TOC clicks
```

### Phase 7 → Phase 8
```
Phase 7 defines:
  Input handlers (keyDown, mouse, touch)

Phase 8 depends on:
  keyDown() routing to feature functions (C, D, W, ?)
  Mouse input for annotation drawing
```

### Phase 8 → Phases 9-11
```
Phase 8 analysis feeds into:
  Phase 9: Toolbar/UI organization → feature button layout
  Phase 10: Actual refactoring → extract features into modules
  Phase 11: Complete decoupling → feature factory pattern
```

---

## Key Findings

### 1. Tight Coupling to Keyboard Input
**Finding:** All 6 features hardwired to specific keys (C, D, W, ?).

**Implication:** Keyboard routing centralized in keyDown(), making feature dispatch difficult to refactor independently.

**Recommendation (Phase 10+):** Extract input → feature mapping to feature dispatcher pattern.

---

### 2. Mode Toggle Side Effects
**Finding:** Feature state affected by slidemode toggle.

**Examples:**
- Canvas destroyed on slidemode exit
- TOC/Help modals closed
- Dark mode persists but rendering updates

**Implication:** Features cannot be independently tested without mode context.

**Recommendation (Phase 10+):** Feature state should be independent of mode; only rendering should be conditional.

---

### 3. displaySlide() Responsibility Creep
**Finding:** displaySlide() calls initIncrementals(), updating multiple feature states.

**Implication:** displaySlide() already highly-coupled (Phase 6 finding); adding feature initialization deepens coupling.

**Recommendation (Phase 10+):** Extract feature initialization callbacks.

---

### 4. Second Window Sync
**Finding:** Dark Mode feature directly posts to Second Window.

**Implication:** Features reaching across system boundaries (Window 2), creating unpredictable sync behavior.

**Recommendation (Phase 10+):** Centralize Second Window communication; features should not directly call postMessage().

---

### 5. Comments and TOC Share Key (C)
**Finding:** toggleComments() and tableOfContents() both bound to C key.

**Implication:** Logic must decide which to call; potential conflict or toggle behavior.

**Recommendation (Phase 9+):** Clarify C key behavior or split into separate keys.

---

### 6. Annotation Canvas Lifecycle
**Finding:** Canvas element created/destroyed dynamically; drawing state not persisted.

**Implication:** Annotations lost when exiting annotation mode or changing slides.

**Recommendation (Phase 10+):** Consider persistent annotation storage if needed.

---

## Architecture Boundary

### What Phase 8 Does NOT Do

- ❌ Combine feature functions into single handler
- ❌ Extract features into separate modules/classes
- ❌ Create feature factory or dispatcher
- ❌ Refactor feature state management
- ❌ Change input routing
- ❌ Rename or move functions
- ❌ Modify feature behavior

### What Phase 8 Only Does

- ✅ Identify 6 feature managers
- ✅ Map state variables per feature
- ✅ Document core functions
- ✅ Identify input triggers (keyboard)
- ✅ Map cross-system dependencies
- ✅ Identify coupling points
- ✅ Document findings for Phase 9-11

---

## Phase 8 Deliverables

### 1. Documentation File
```
docs/phase8-feature-managers.md
├─ Scope & Boundary
├─ 6 Feature Managers (with state, functions, dependencies)
├─ Feature → Input Mapping
├─ Feature → State/DOM/API Mapping
├─ Cross-Feature Coupling
├─ Dependencies Between Phases
├─ Key Findings & Recommendations
└─ Architecture Boundary
```

### 2. Code Boundary Comments
```javascript
/* ===== Feature Managers ===== */
// 6 independent feature subsystems: Incrementals, Comments, TOC, Help, Dark Mode, Annotation
// See: docs/phase8-feature-managers.md for complete analysis
//
// Incrementals: initIncrementals, nextSlideOrElt, previousSlideOrElt
// Comments: toggleComments, trackVisibleSlides
// Table of Contents: tableOfContents, getSlideTitle, createTOCText
// Help: help
// Dark Mode: toggleDarkMode, initDarkMode
// Annotation: toggleAnnotate
//
// All features triggered via keyDown() input routing (C, D, W, ?)
// All features share dependencies on Navigation, Mode Toggle, UI, and Second Window sync
```

---

## Phase 8 vs Phase 10 Refactoring

```
Phase 8 (Now)                    | Phase 10-11 (Refactoring)
─────────────────────────────────┼───────────────────────────────────
Document features as-is          | Restructure features into modules
Identify tight couplings         | Decouple via dependency injection
Map keyboard routing             | Extract feature dispatcher pattern
Find state duplication           | Consolidate feature state
Highlight problematic patterns   | Apply design patterns (Factory, etc.)
No code changes                  | Full refactoring + API changes
```

---

**Status:** ✅ Phase 8 Ready for Documentation

**Next:** Add boundary comments to code + create phase8-feature-managers.md + Commit

**Then:** Phase 9 (Toolbar/UI Organization)
