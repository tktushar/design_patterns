A C programmers take on the C++ programming language.

I journal my ideas here, things that I encounter on my way to learning OOP paradigm in C++. This is basically a collection of all the shockers and jolts to the muscle memory that I had as a C style C++ guy. Note that I was already familiar with C++ and wasn't a total begineer.

1. Libraries don't have .h
2. enum {} vs enum class {}:
   1. enum class has scoping. enum class Color {RED, GREEEN} is referenced as Color::RED 
   2. No implicit type conversion when using class. Each is essentially a class
   3. Can't forward declare enum class.
<pre>
<code>
enum Color {
    RED,
    GREEN,
    BLUE
};
    // No type safety - implicit conversion to int
    int colorValue = myColor;

    // This is allowed, but it might lead to unintended behavior
    Color anotherColor = static_cast<Color>(colorValue);

enum class Color {
    RED,
    GREEN,
    BLUE
};

   // This is required for the conversion
    int colorValue = static_cast<int>(myColor);

</code>
</pre>

3. map.insert will not overwrite the key, but map[key] will overwrite if its already present

### Class Creation Observations
1. Without 'override' keyword, the parent class's virtual function will run. Though, missing override would not give any warning. This is some backwards compatibility thing.
2. If class C inherits class B and class B inherits class A, and B overrides a pure virtual function in A, C can override this same function even when defined in B.

## Misc
1. this vs *this. this is a pointer, *this is a deferenced object. While returning from a function, return a referecne when you don't want to return a clone because returning *this will create a clone on the stack.

2. Singleton(const Singleton&) = delete; 
   This deletes the copy constructor, see how no variable name is required.
   Singleton(const Singleton& instance) = delete;

## Design Patterns 
Gamma Categorization :
1. Creational : deals with creations of objects : explicit/implicit. Can be wholesale or piecewise
2. Structural Patterns : Concerned with structure (eg. class memebers). Usually wrappers. Stress on good API design
3. Behavioural Patterns : all different, no central theme