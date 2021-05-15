# Google Code Jam 2021

This repository contains my solutions to the problems from [Google Code Jam 2021][1].

## Instructions

You can compile all problems by issuing the following command:

    $ make

If you want to compile only a specific problem, issue the following command, replacing `<problem_id>` with the section and identifier of the problem you want to compile (see section "Problems Solved" for the list of possible identifiers):

    $ make <problem_id>

Running a compiled problem is just a matter of executing a command similar to the next one, replacing `<problem_id>` with the identifier of the desired problem:

    $ ./<problem_id>

Every problem in this repository reads from the standard input and writes to the standard output.

## Problems Solved

The following is the list of the problems solved. Each problem identifier is specified between round brackets. Problems marked with ✓ are done, while problems with ✗ are not complete or aren't efficient enough for all the limits specified in the problem.

### Qualification Round

* ✓ [A. Reversort][qual1] (`reversort`)
* ✓ [B. Moons and Umbrellas][qual2] (`moons-and-umbrellas`)
* ✓ [C. Reversort Engineering][qual3] (`reversort-engineering`)
* ✓ [D. Median Sort][qual4] (`median-sort`)
* ✓ [E. Cheating Detection][qual5] (`cheating-detection`)

### Round 1B

* ✓ [A. Broken Clock][round1b1] (`broken-clock`)
* ✓ [B. Subtransmutation][round1b2] (`subtransmutation`)
* ✗ [C. Digit Blocks][round1b3] (`digit-blocks`)

[1]: https://codingcompetitions.withgoogle.com/codejam
[qual1]: https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d0a5c
[qual2]: https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d1145
[qual3]: https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d12d7
[qual4]: https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d1284
[qual5]: https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d1155
[round1b1]: https://codingcompetitions.withgoogle.com/codejam/round/0000000000435baf/00000000007ae694
[round1b2]: https://codingcompetitions.withgoogle.com/codejam/round/0000000000435baf/00000000007ae4aa
[round1b3]: https://codingcompetitions.withgoogle.com/codejam/round/0000000000435baf/00000000007ae37b
