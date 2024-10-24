The OpenClosedPrinciple (OCP): "A reusable class should be open for extension, but closed for modification." 
Use abstraction and dynamic binding (Polymorphism) to avoid dependency on a concrete class
A class must not depend on a concrete class
It must depend on an abstract classusing polymorphic dependencies
“Client” knows its interface only without knowing “Server”

Requirement Changed: Draw all circles before squares
We have no protection against this kind of change
How can we get closure against this?
In order to closure something, we always need an abstraction that hide the ‘variable’ part of the design.
But, How do we know what to hide. i.e., What kind of abstraction to create?
"No significant program can be 100% closed. Therefore, closure should not be
complete but strategic " 

Use abstraction to gain explicit closure
provide class methods which can be dynamically invoked
to determine general policy decisions 
e.g. draw Squares before Circles
design using abstract ancestor classes
Use "Data-Driven" approach to achieve closure 
place volatile policy decisions in a separate location
e.g. a file or a separate object 
minimizes future change locations

There is no model that is natural to all context. 
Apply OCP to most obvious changes, The possible changes can be any design decision. Many of them can not be dealt with the standard object oriented way.

The other approach: 
“Fool me once, shame on you,  Fool me twice, shame on me.
Once a change of some type has occurred, it is probable that a chance of same type will occur later. Apply OCP when it is needed the first time.
Another good strategy:
Stimulate early changes –TDD
Fast iteration, constant feedback
So with fast iterations, you can actually create better design. \

Conformance to OCP yields the greatest benefits claimed for object oriented technology
Flexibility, reusability, maintainability
However, Conformance to OCP can not be achieved simply by using an OO languages, but by finding a natural structure for the context, in which it is possible to abstract out the variability
E.g. put possibly changing policy decision in a single separate location and close the client code against changes in that policy
Conformance to OCP does not come for free. Choose carefully where to apply it, and where consciously not.

