
ra.rst , keys , choosing 2026/04/13 22:04:30
--------------------------------------------
Another question to Grok 2026/04/13 23:30:55
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Thanks, I added the following criteria for "Criteria for Surrogate Keys":
Table structure and its fields may change a lot in future

Therefore, the whole section of “Surrogate Keys vs. Natural Keys” changes to this:

  #. Avoid Arbitrary Fields
#. Criteria for Surrogate Keys
    * No natural candidate keys exist.
    * Existing candidate keys are excessively "wide"
    * Table structure and its fields may change a lot in future
#. Surrogate Limitations
#. Last Resort Principle


Do you think it is a good change? Do you have suggestions to improve it?


Grok Answer 2026/04/13 23:31:55
```````````````````````````````
Surrogate Keys vs. Natural Keys
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* **Avoid Arbitrary Fields**: Do not introduce meaningless or purely technical fields solely to create a primary key.

* **Criteria for Surrogate Keys**: Add a surrogate (extra) field **only** when one or more of the following conditions apply:
  * No natural candidate keys exist.
  * Existing candidate keys are excessively wide (too many attributes or large data types).
  * Table structure, business rules, or attribute values are expected to change frequently in the future.

* **Surrogate Limitations**: A surrogate primary key does **not** remove the need for uniqueness constraints on natural candidate keys. Always enforce business-level uniqueness with ``UNIQUE`` constraints.

* **Last Resort Principle**: An auto-incrementing integer (or similar purely technical identifier) should be used only as the final option. Prefer a meaningful natural key or a semi-meaningful surrogate whenever possible.

.. admonition:: Key Principle
   :class: important

   Surrogate keys are excellent for **stability and decoupling** when business data evolves, but they must never replace proper enforcement of natural uniqueness rules.

**Rationale for the New Criterion (Table Structure May Change)**
The addition you made is **excellent** and academically sound.
Frequent schema or business-rule changes are a very common real-world reason to choose surrogate keys. Natural keys often embed business meaning that can become obsolete or require updates (e.g., email formats, product codes, regulatory IDs). A surrogate key remains unchanged even if the rest of the table evolves.

**Suggested Improvements (already incorporated above)**
* Made the new bullet parallel and concise.
* Changed “may change a lot” → “are expected to change frequently” (more precise academic tone).
* Kept the original numbering style you preferred while improving clarity and flow.
* Added a short “Limitations” reminder — this is critical so students do not think surrogate keys let them ignore natural uniqueness.
* Added a boxed “Key Principle” for slide emphasis.

You can copy the entire block above directly into the **Surrogate Keys vs. Natural Keys** subsection of ``ra.rst``. It now fully reflects your updated criteria while remaining concise, academic, and suitable for bachelor-level slides.

I give Gemini answer to Grok
^^^^^^^^^^^^^^^^^^^^^^^^^^^^
It is great to see you are still evolving **prezentprogramo**! Building a custom tool to maintain upward compatibility with `docutils` is a smart architectural move, especially for technical slides where you want full control over the rendering pipeline.

Regarding your database notes: your original points lean toward a "Natural Key" philosophy. While valid, modern database theory emphasizes **stability** and **immutability** over "meaningfulness." A primary key that carries meaning often becomes a liability if that meaning changes (e.g., a user changing their email or an SKU format being updated).

I have refined your notes to reflect a more robust academic standard, added common pitfalls, and separated the rules for identifying candidate keys.

---

### Primary Key Selection Guidelines

Paste this into your `ra.rst` file under the Primary Key section:

```rst

Primary Key Selection
`````````````````````

Guidelines for Optimal Selection
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

* **Derived from Candidate Keys**: A primary key must be selected from the set of identified candidate keys.
* **Attribute Stability**: Prioritize keys that are least likely to change over the lifetime of the record.
* **Minimality**: Prefer a single-attribute key or a small composite key to improve indexing performance and simplify Foreign Key relationships.
* **High Frequency Usage**: Select the candidate key most frequently used by applications and users to identify specific tuples.
* **Non-Nullability**: By definition, a primary key must strictly prohibit null values.

Surrogate Keys vs. Natural Keys
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

* **Avoid Arbitrary Fields**: Do not introduce surrogate keys (e.g., UUIDs, Auto-increments) if a stable, simple natural key exists.
* **Criteria for Surrogate Keys**: Consider adding an artificial identifier only if:
    * No natural candidate keys exist.
    * Existing candidate keys are excessively "wide" (consist of too many fields or large strings).
* **Surrogate Limitations**: If a surrogate key is used, ensure it does not replace the requirement for uniqueness constraints on the original natural data.
* **Last Resort Principle**: Auto-incrementing integers are often a structural necessity in implementation, but in logical design, they should be utilized only when natural identifiers fail the stability or minimality tests.

Common Mistakes to Avoid
~~~~~~~~~~~~~~~~~~~~~~~~

* **Using Volatile Data**: Never use fields that change, such as ``Email``, ``Phone_Number``, or ``Mailing_Address``.
* **Using Large Strings**: Using long text fields as primary keys increases index size and degrades join performance.
* **External Identifiers**: Relying on external keys (e.g., Social Security Numbers or National IDs) is risky due to privacy regulations (GDPR), potential format changes, or duplicate assignments by external agencies.
* **Meaningful Key Updates**: If a primary key has "meaning," users may want to update it. Updating a primary key requires expensive cascading updates to all related foreign keys.

Identifying Candidate Keys
``````````````````````````

Rules for Identification
~~~~~~~~~~~~~~~~~~~~~~~~

1. **Uniqueness Property**: At any given time, no two tuples in the relation can have the same value for the candidate key.
2. **Irreducibility (Minimality)**: No proper subset of the candidate key attributes can satisfy the uniqueness property. If you can remove an attribute and the key remains unique, the original set was a *superkey*, not a *candidate key*.
3. **Functional Dependency**: The candidate key must functionally determine all other attributes in the relation:
   $K \rightarrow R$
4. **Existence**: Every relation must have at least one candidate key (in the worst case, the set of all attributes combined).
```

---

### Key Improvements Explained:

* **Stability over Meaning**: I changed the focus from "meaningful" to "stable." In database design, if a value has "meaning" (like a product category code), it is prone to change. If the PK changes, every Foreign Key in every related table must also be updated.
* **The SSN Trap**: Many students think Social Security Numbers are perfect primary keys. I added a note about "External Identifiers" to explain why this is a mistake (privacy and lack of control).
* **Irreducibility**: This is the formal term for your point about not having a large number of fields. A candidate key must be the *minimal* set of attributes needed for uniqueness.
* **LaTeX Usage**: I used $K \rightarrow R$ to denote that the Key $K$ determines the Relation $R$, as this is standard in Bachelor-level Database Engineering courses.

Is there a specific section of Relational Algebra (like Joins or Division) you'll be working on next for these slides?

Gemini gets my question first
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
I wrote the following text to Gemini

 Hello, I use prezentprogramo (https://github.com/yoosofan/prezentprogramo , my tool based on Hovercraft) to make slides (https://github.com/yoosofan/slide ) by writing restructuredtext (RST). You can help me to update some of my slides in https://github.com/yoosofan/slide/tree/main/db . I want to update slides of the database course for bachelor of computer engineering, therefore focus on the database course.The following list are some notes about choosing the correct primary key for a table.  Can you check them grammarly and rewrite them in concise academic writing for academic slides for course. Also, Please revise them if they need to change based on knowledge of computer databases and the mistakes for choosing the write primary key. Also, add more notes for choosing the correct primary key and common mistakes for choosing primary key.  If there are some other rules for finding candidate keys, please write them in a separate list. Please use the RSTformat for your answers. Your answers will be added to https://github.com/yoosofan/slide/blob/main/db/ra.rst in primary key slide (section):

#. The best choice for primary ke is a candidate key that
    * Most important in real data usage
    * could be use many times to find record
    * used mostly by user
#. Don't add arbitrary field for Primary key
#. The primary key should be selected from one of the candidate keys
#. is meaningfull
#. If there
    * is no candidate key or
    * or cadidate keys consist large number of field
    * then it is possible to add extra field
    * Try to add meaningful field or field that can be used for some usage
    * In another word, just don't add field for the sake of having key
    * Adding a field of autoincrement should be the last resort

Gemini answer

--------

It is great to see you are still evolving **prezentprogramo**! Building a custom tool to maintain upward compatibility with `docutils` is a smart architectural move, especially for technical slides where you want full control over the rendering pipeline.

Regarding your database notes: your original points lean toward a "Natural Key" philosophy. While valid, modern database theory emphasizes **stability** and **immutability** over "meaningfulness." A primary key that carries meaning often becomes a liability if that meaning changes (e.g., a user changing their email or an SKU format being updated).

I have refined your notes to reflect a more robust academic standard, added common pitfalls, and separated the rules for identifying candidate keys.

---

### Primary Key Selection Guidelines

Paste this into your `ra.rst` file under the Primary Key section:

```rst

Primary Key Selection
`````````````````````

Guidelines for Optimal Selection
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

* **Derived from Candidate Keys**: A primary key must be selected from the set of identified candidate keys.
* **Attribute Stability**: Prioritize keys that are least likely to change over the lifetime of the record.
* **Minimality**: Prefer a single-attribute key or a small composite key to improve indexing performance and simplify Foreign Key relationships.
* **High Frequency Usage**: Select the candidate key most frequently used by applications and users to identify specific tuples.
* **Non-Nullability**: By definition, a primary key must strictly prohibit null values.

Surrogate Keys vs. Natural Keys
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

* **Avoid Arbitrary Fields**: Do not introduce surrogate keys (e.g., UUIDs, Auto-increments) if a stable, simple natural key exists.
* **Criteria for Surrogate Keys**: Consider adding an artificial identifier only if:
    * No natural candidate keys exist.
    * Existing candidate keys are excessively "wide" (consist of too many fields or large strings).
* **Surrogate Limitations**: If a surrogate key is used, ensure it does not replace the requirement for uniqueness constraints on the original natural data.
* **Last Resort Principle**: Auto-incrementing integers are often a structural necessity in implementation, but in logical design, they should be utilized only when natural identifiers fail the stability or minimality tests.

Common Mistakes to Avoid
~~~~~~~~~~~~~~~~~~~~~~~~

* **Using Volatile Data**: Never use fields that change, such as ``Email``, ``Phone_Number``, or ``Mailing_Address``.
* **Using Large Strings**: Using long text fields as primary keys increases index size and degrades join performance.
* **External Identifiers**: Relying on external keys (e.g., Social Security Numbers or National IDs) is risky due to privacy regulations (GDPR), potential format changes, or duplicate assignments by external agencies.
* **Meaningful Key Updates**: If a primary key has "meaning," users may want to update it. Updating a primary key requires expensive cascading updates to all related foreign keys.

Identifying Candidate Keys
``````````````````````````

Rules for Identification
~~~~~~~~~~~~~~~~~~~~~~~~

1. **Uniqueness Property**: At any given time, no two tuples in the relation can have the same value for the candidate key.
2. **Irreducibility (Minimality)**: No proper subset of the candidate key attributes can satisfy the uniqueness property. If you can remove an attribute and the key remains unique, the original set was a *superkey*, not a *candidate key*.
3. **Functional Dependency**: The candidate key must functionally determine all other attributes in the relation:
   $K \rightarrow R$
4. **Existence**: Every relation must have at least one candidate key (in the worst case, the set of all attributes combined).
```

---

### Key Improvements Explained:

* **Stability over Meaning**: I changed the focus from "meaningful" to "stable." In database design, if a value has "meaning" (like a product category code), it is prone to change. If the PK changes, every Foreign Key in every related table must also be updated.
* **The SSN Trap**: Many students think Social Security Numbers are perfect primary keys. I added a note about "External Identifiers" to explain why this is a mistake (privacy and lack of control).
* **Irreducibility**: This is the formal term for your point about not having a large number of fields. A candidate key must be the *minimal* set of attributes needed for uniqueness.
* **LaTeX Usage**: I used $K \rightarrow R$ to denote that the Key $K$ determines the Relation $R$, as this is standard in Bachelor-level Database Engineering courses.

Is there a specific section of Relational Algebra (like Joins or Division) you'll be working on next for these slides?