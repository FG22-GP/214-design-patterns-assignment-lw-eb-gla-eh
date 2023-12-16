Description: Our project is an implementation of the game "Snake". We setup the inputs, game loop and we focused quite a bit on separating the game logic and "engine logic" and discussed a lot about what should communicate\be aware of what.

# Design patterns

## Observer Patter

### Some reasoning:
Observer being the staple that it is, we decided to implement this pattern before we even decided on what game to make. We started out by considering taking a more “default” approach of creating an Event and Listener class and having other classes inherit from them. Events would simply have a Broadcast() function and a list of listeners (as well as a way to subscribe and unsubscribe). The more “clean” way of implementing events (according to us) would be that the class responsible for sending the event would not inherit from Event, but rather create an Event and just tell it when to broadcast (This way we can also have more than 1 event per class :) ). The problem with this is that listeners could not simply just do the same. Listeners would have to inherit from the listener class (which is inconsistent when events are created) **or** have function pointers  <sub>(unless of course we create very specific listener subclasses, but that's just … wrong)</sub> . The problem here was that we did, at this point, not know how to implement function pointers. So we ~~googled~~ researched it. Once we knew how function pointers worked, we thought that we might as well create delegates, multicast delegates and allow for parameters in these (up to a maximum of 1, cause we didnt need more for this project. Creating more is just a task of copypasting).
 

### Implementation

We implement delegates with these lines of code:

```
ThingWithDelegate.h:
RE_MulticastDelegate1<Param> DelegateName;

ThingThatWantsToKnowThing.cpp:
ThingWithDelegate->DelegateName += RE_DelegateMember1(this, &ThingThatWantsToKnowThing::Function);
```

The first thing that utilized the observer pattern was the input. When keys are pressed
InputManager broadcasts that. Then we have a snake that is subscribed to it. Another use of the pattern is the fire of the event when the snake has moved. That is a convenient way to check if something should happen at that moment (Hit wall, ate yourself, ate apple) and we can subscribe to those events separately. 

## GameLoop

### Implementation

Being avid Unreal and Unity users, we wanted to create a similar framework to work within. Creating a semi-proper game loop was therefore very much on our ToDo-list. 

Our game loop is broken down into multiple manager classes, each responsible for its own systems and ends up looking like this:

```
void RE_GameLoop::Update()
{
    SDL_Event Event;
    while (!InputManager->ShouldQuit(Event))
    {
        float DeltaTime = CalculateDeltaTime();
        RenderHandler->ClearRender();

        InputManager->RegisterInput();
        FixedUpdate(DeltaTime); //FixedUpdate checks itself if it should call or not 
        EntityManager->Update(DeltaTime);
        RenderHandler->RenderStuff();
    }
}
```

Before Update() starts we also start up our managers and initialize whatever we might need for them. 

Our next step of improving our loop would be to move it into states so that our game would be easily restartable with something like this:

```
//somewhere here is a syntax error as a “fun” exercise for the reader :)
void RE_GameLoop::Run()
{
	switch (Gamestate)
	{
	case Gamestate::STARTING:
		Start();
		break;
	case Gamestate::UPDATING:
		Update();
		break;
	case Gamestate::EXITING:
		Exit();
		break;
	default:
		break;
	}
}
```

This way would could make a simple Restart() that we could call when we, well, would need to restart. 
(and probly also something like a MoveToNextState() )
