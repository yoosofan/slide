//	https://stackoverflow.com/questions/752658/is-the-practice-of-returning-a-c-reference-variable-evil
//	https://stackoverflow.com/a/752699/886607

//	In general, returning a reference is perfectly normal and happens all the time.
//	If you mean:

int& getInt() {
    int i;
    return i;  // DON'T DO THIS.
}

//	That is all sorts of evil. The stack-allocated i will go away and you are referring to nothing. This is also evil:

int& getInt() {
    int* i = new int;
    return *i;  // DON'T DO THIS.
}

//	Because now the client has to eventually do the strange:

int& myInt = getInt(); // note the &, we cannot lose this reference!
delete &myInt;         // must delete...totally weird and  evil

int oops = getInt();
delete &oops; // undefined behavior, we're wrongly deleting a copy, not the original

//	Note that rvalue references are still just references, so all the evil applications remain the same.

//	If you want to allocate something that lives beyond the scope of the function, use a smart pointer (or in general, a container):

std::unique_ptr<int> getInt() {
    return std::make_unique<int>(0);
}

//	And now the client stores a smart pointer:

std::unique_ptr<int> x = getInt();

//	References are also okay for accessing things where you know the lifetime is being kept open on a higher-level, e.g.:

struct immutableint {
    immutableint(int i) : i_(i) {}

    const int& get() const { return i_; }
private:
    int i_;
};

//	Here we know it's okay to return a reference to i_ because whatever is calling us manages the lifetime of the class instance, so i_ will live at least that long.

//	And of course, there's nothing wrong with just:

int getInt() {
   return 0;
}

//	If the lifetime should be left up to the caller, and you're just computing the value.

//	Summary: it's okay to return a reference if the lifetime of the object won't end after the call.
