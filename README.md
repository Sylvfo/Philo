## φ Philo

*Simulation of the classical Dining Philosophers problem using threads and mutexes to prevent deadlocks and race conditions*

**Languages & Tools:** C, Pthreads (mutex, thread management), valgrind helgrind

**Skills:** Multithreading, synchronization, concurrency control, debugging timing issues

### Something interesting about this project ✨
Not sure if Socrate would have appreciate this... But for IT people, philosophers only eat, sleep, think, repeat,...
All of them possess only one fork, but need 2 to have dinner. If they do not eat often enough, they die. If one die, they all die.
Everything about this project is to help them sharing forks so they can all eat their turn. Each philo is a thread and each fork a mutex.

Wait! Is it ok to consider a bunch of men with huge egos need to be monitored to do different things in the same time and be kind enough to each other to share their forks in an equal way???
Apparently yes...

When it is an even number of philosophers, it is easy. They can alternate between odd and even to share the forks. You -> Your right friend -> You ->  Your right friend -> ...

But what happens when there is an odd number of philosophers?
<img width="1831" height="744" alt="image" src="https://github.com/user-attachments/assets/340a3718-bdd1-4df4-9d1b-4f74028006b0" />
How to handle with precision the ballet of the forks so we do not loose time or ressources?

This is where the algorithm gets interesting — good design is everything.

Ahah, teaching these philosophers to clean their own fork make the programm way way more performing. 
And what happen is they don't do it? A Data Race incident can occure... And the programm will crash.

Thank Gods, the Nordic mythology provide us the godess Hel who will check if they behave well. 

Evaluation reviews

*Belle demonstration avec beaucoup d'explications, a pu repondre sans soucis a toutes mes questions :) Jolie metaphore pour l'ordre de priorites des fourchettes dans le cas ou les philos sont en nombre impaire. Bonne suite a toi ! :D*
MW

*Impressive, probably the most advanced version of philosophers I've come across. Works even for 600 philosophers. What even is this. Great job.*
JB

### 🖥️ Compilation & Usage

```bash
$> make
$> ./philo number_of_philosophers, time_to_die, time_to_eat, time_to_sleep, [number_of_times_each_philosopher_must_eat]
$> ./philo 4 500 150 200
$>
$> ./philo 7 100 49 49
$>
$> ./philo 600 400 20 25
$> ...

```
<img width="393" height="1154" alt="image" src="https://github.com/user-attachments/assets/685b8bb8-79c3-4cca-9502-3d67333dccaf" />
<img width="393" height="1154" alt="image" src="https://github.com/user-attachments/assets/8621a6be-06ab-42b5-a428-b909fa34aef8" />



