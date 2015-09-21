title: Overloading
task_id: M2-OVERLOAD
points: 3


**Objective:** Refresher on function overloading (see module 1), and
  sneak peak on templates (next round)

The exercise is in three parts, each of which is worth one point.

**Part I**: Implement three variants of function **area** that
  calculates the area of [circle] (based on radius), [rectangle] (based on
  width and height), and [trapezoid] (based on the lengths of the
  parallel sizes and height).

[circle]: https://en.wikipedia.org/wiki/Circle
[rectangle]: https://en.wikipedia.org/wiki/Rectangle
[trapezoid]: https://en.wikipedia.org/wiki/Trapezoid

**Part II**: Write three variants of function **add** that calculates
  the sum of a) two integers; b) two double values; c) concatenates
  two strings

**Part III**: Write function **sum** that calculates sum of two
  generic arguments. The two arguments can be of any type, as long as
  the type supports the `+` operator. You should use *template* to
  implement this function. There will be more about templates in next
  module, but a good information package is availale at the end of
  [this page](http://www.cplusplus.com/doc/tutorial/templates/)
