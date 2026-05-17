# Thanks to chatgpt.com for making this code
# I put simplified version in ../

class Parser:
    def __init__(self, text):
        self.text = text
        self.pos = 0

    # -------------------------------------------------
    # Utility functions
    # -------------------------------------------------

    def current_char(self):
        if self.pos < len(self.text):
            return self.text[self.pos]
        return None

    def match(self, token):
        if self.text.startswith(token, self.pos):
            self.pos += len(token)
            return True
        return False

    def error(self, message):
        raise SyntaxError(
            f"{message} at position {self.pos}"
        )

    # -------------------------------------------------
    # Grammar:
    #
    # S:
    #   a* B+
    #
    # B:
    #   b* ab (a B)*
    # -------------------------------------------------

    def S(self):
        print("Enter S")

        # 0 -> 0 [a]
        while self.match('a'):
            print("S: consume 'a'")

        # 0 -> 1 [B]
        self.B()

        # 1 -> 1 [B]
        while self.current_char() in ('a', 'b'):
            old_pos = self.pos

            try:
                self.B()
            except SyntaxError:
                self.pos = old_pos
                break

        print("Exit S")

    def B(self):
        print("Enter B")

        # 0 -> 0 [b]
        while self.match('b'):
            print("B: consume 'b'")

        # 0 -> 2 [ab]
        if self.match('ab'):
            print("B: consume 'ab'")
        else:
            self.error("Expected 'ab'")

        # 2 -> 0 [a]
        while self.match('a'):
            print("B: recursive 'a B'")
            self.B()

        print("Exit B")

    # -------------------------------------------------
    # Parse entry
    # -------------------------------------------------

    def parse(self):
        self.S()

        if self.pos != len(self.text):
            self.error("Unexpected input")

        print("\nInput accepted.")


# -------------------------------------------------
# Example usage
# -------------------------------------------------

samples = [
    "ab",
    "aab",
    "bbab",
    "abbab",
    "aaabbab",
]

for s in samples:
    print("\n====================")
    print("Input:", s)

    try:
        parser = Parser(s)
        parser.parse()
    except SyntaxError as e:
        print("Syntax Error:", e)
