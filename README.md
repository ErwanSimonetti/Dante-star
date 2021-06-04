# Dante's star

Epitech's RPG project done with my colleague Martin BLANCHO. The project started on the 29th of March 2021 and finished on the 18th of April 2021.

The generator part generates a perfect or imperfect maze according to your choice, and the solver part solves it.

To try it, clone the repository and follow these steps :

# Generator

Go in the generator folder. Use the make rule to create the generator binary file.

USAGE:

./generator x y [perfect]

As the perfect argument is optional, the default generation will be an imperfect maze.

You can redirect the generated map into a file using the > redirection : ./generator x y [perfect] > maze.txt

# Solver

Go in the solver folder. Use the make rule to create the solver binary file.

USAGE:

./solver maze.txt
