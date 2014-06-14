qQqq
====

A bad joke of a programming language. It's pronounced "Qfrzkkndqy"

## But WHY?

As was written in my Linear Algebra textbook, *Introduction to Linear Algebra,
4th ed*, "Stable computer codes use as many Qs as possible". The topic of
discussion was QR factorization, but the statement was otherwise unqualified.

As such, I decided tha to make the most stable computer program possible, only
the characters 'q' and 'Q' should be used. Indeed, in qQqq using any other
character is a syntax error!

## Syntax

It takes signficant inspiration from Brainfuck, but allows for a little more
flexibility down the road. The following instructions are known right now:

| Instruction | Effect |
| ----------- | ------ |
| QQ          | Increment the current cell's value |
| qQ          | print the current cell's value as if it represents ascii |
| qq          | Decrement the current cell's value |

The important thing to notice is that Qq as a pair of characters are unused.
These are reserved to add furthre functionality like being able to advance
through cells and implement looping constructs. I thought I had already done
that, but looking at the code I guess not.

## Preprocessing

For the interpreter to be as stable as possible, it was necessary to create a
preprocessor (preprocess.rb) that makes the interpreter use as many 'Q's as
possible too. 'q.c' is the unprocessed source code while 'qQqq.c' is the
processed interpreter which you should use to ensure your code is stable.


## License

I absolutely don't care what you do to this. Say you made it if you want because
heck knows I won't be bragging about this dumb idea.
