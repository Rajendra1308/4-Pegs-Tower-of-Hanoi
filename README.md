# 4-Pegs-Tower-of-Hanoi

The 3-peg version is well understood, and its time complexity is easily provable. The *4-peg version* eluded mathematicians for over a century. In 1941, **J.S. Frame** and **B.M. Stewart** independently proposed a particular way of solving the 4-peg puzzle, which is popularly known as the **Frame–Stewart algorithm** (see below). In 1994, **Paul Stockmeyer** calculated an approximate closed-formexpression for the optimal number of moves made by the **Frame–Stewart algorithm**. Very recently, **Roberto Demontis** (December 2018) proved that the Frame–Stewart algorithm is indeed optimal.

There are four pegs A,B,C,D(numbered as 0,1,2,3). Initially, n disks of diameters 1,2,3,...,n are stacked on Peg A in the sorted order (the smallest disk at the top, and the largest disk at the bottom). The three other pegs are initially empty. Your task is to transfer the n disks from Peg A to Peg B taking help from the other two pegs, using a sequence of moves. Each move transfers a single disk d from Peg p to Peg q (p<=q),such that the following two conditions hold just before the movement: (i) Disk d must be sitting at the top of Pegp, and (ii) Disk d is not allowed to be larger than the disk (if any) sitting on the top of Peg q.

If only three pegs are allowed, we know that the best (minimum) number of moves is T3(n) =2<sup>n</sup>−1, and a ***straight forward divide-and-conquer algorithm*** solves the 3-peg puzzle using exactly these many moves. If we are allowed to use a fourth peg, the **Frame–Stewart algorithm** is used, which involves the following steps (also see the figure on the next page).

*1. If n<=3, solve the problem directly.*

*2. Fix a value of k in the range 1<= k <= n.*

*3. Keep the k largest disks on Peg A, and transfer the smallest n−k disks from Peg A to Peg D.*

*4. Transfer the largest k disks from Peg A to Peg B without disturbing the smallest n−k disks already sitting on Peg D. Since a larger disk can never be put on the top of a smaller disk, Peg D is unusable in this part, that is, we solve the 3-peg Tower-of-Hanoi problem on k disks.*

*5. Transfer the smallest n−k disks from Peg D to Peg B without disturbing the largest k disks on Peg B.In this step, all the four pegs can be used.*

**T<sub>4</sub>(n) =T<sub>4</sub>(n−k)+T<sub>3</sub>(k)+T<sub>4</sub>(n−k) =2T<sub>4</sub>(n−k)+2<sup>k</sup>−1.**


**Function ToH3(i,j,p,q,r)** to transfer Disks i through j from Peg p to Peg q using a third Peg r.

**Function ToH41(i,j,p,q,r,s)** to transfer Disks i through j from Peg p to Peg q using the two other pegs r and s. Here, you take **k=⌊m/2⌋** (where m=j−i+1 as defined above). This is a natural choice of breaking the problem into two equal halves, but this choice turnsout to be quite poor.

**Function ToH42(i,j,p,q,r,s,k)** to transfer Disks i through j from Peg p to Peg q using the two other pegs r and s. Here, we use a fixed value of k independent of the size m=j−i+1 of the subproblem posed to the recursive invocation. If m<=k, solve the problem using the 3-peg Tower-of-Hanoi algorithm. Otherwise, follow the **Frame–Stewart algorithm.**

It turns out that the optimal choice fork is **{√2m}** for a recursive call on m disks, where **{x}** is theinteger nearest to x. As shown by Stockmeyer, this choice of k leads to **T4(n)≈√n2<sup>√(2n)</sup>.** Write a functionToH43(i,j,p,q,r,s) to implement this optimal version, where i,j,p,q,r,s (and m) are as explained above.
