Description: Our project is an implementaion of the game "Snake". We setup the inputs, game loop and we focused quite a bit
on separating the game logic and "engine logic" and discussed a lot what should communicate\be aware of what.

Design patterns:
	Observer Pattern: We needed to make delegates work for this pattern so that was the first thing we researched on how to do.
we learnt how to store pointers to functions. The first thing that utilized the observer pattern was the input. When keys are pressed
InputManager broadcasts that. Then we have a snake that is subscribed to it. Another use of the pattern is the fire of the event when the snake
has moved. That is a convenient way to check if something should happen in that moment (Hit wall, ate yourself, ate apple) and we can subscribe those
events separately
We chose this pattern for the convenient way to make things communicate between each other.

