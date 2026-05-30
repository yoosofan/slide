.. prezento:: CM - Some.Changes.By.The.Help.Of.Ai

.. slido::

    Some Graphvize Charts

.. slido:: ChatGpt.com

    Grammar: A → A α | β, sentence: βαα
    ```````````````````````````````````
    Graphviz is a tool for making image based on DOT language. Consider yourself in this chat as computer scientist and faculty of computer engineeting department. In compiler design course, we need to teach students about Left Recursive elimination. One example is the following grammar:

    A → A α | β

    The following string is a sentence in the above grammar:
    βαα

    **Answer 2026/05/07 10:55:24**
    ```dot
    digraph ParseTree {
        rankdir=TB;
        node [shape=circle];

        // Root
        A0 [label="A"];

        // First production: A → A α
        A1 [label="A"];
        alpha1 [label="α"];

        A0 -> A1;
        A0 -> alpha1;

        // Second production: A → A α
        A2 [label="A"];
        alpha2 [label="α"];

        A1 -> A2;
        A1 -> alpha2;

        // Third production: A → β
        beta [label="β"];

        A2 -> beta;
    }
    ```

    This parse tree derives the sentence:

    [
    A \Rightarrow A\alpha \Rightarrow A\alpha\alpha \Rightarrow \beta\alpha\alpha
    ]

    which corresponds to the string:

    [
    \beta \alpha \alpha
    ]

    Grammar: A → A α | β, sentence: βαα
    ```````````````````````````````````
    Consider the following grammar and the same sentence(βαα) and make parse a tree
    A  → β A'
    A' → α A'
    A' → λ

    **Answer 2026/05/07 11:55:24**
    ```dot id="lr_elimination_parse_tree"
    digraph ParseTree {
        rankdir=TB;
        node [shape=circle];

        // Root
        A [label="A"];

        // A → β A'
        beta [label="β"];
        Aprime1 [label="A'"];

        A -> beta;
        A -> Aprime1;

        // A' → α A'
        alpha1 [label="α"];
        Aprime2 [label="A'"];

        Aprime1 -> alpha1;
        Aprime1 -> Aprime2;

        // A' → α A'
        alpha2 [label="α"];
        Aprime3 [label="A'"];

        Aprime2 -> alpha2;
        Aprime2 -> Aprime3;

        // A' → λ
        lambda [label="λ"];

        Aprime3 -> lambda;
    }
    ```

    This parse tree derives:

    [
    A \Rightarrow \beta A'
    \Rightarrow \beta \alpha A'
    \Rightarrow \beta \alpha \alpha A'
    \Rightarrow \beta \alpha \alpha
    ]

    So the generated sentence is again:

    [
    \beta \alpha \alpha
    ]
