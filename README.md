# 4-Pegs-Tower-of-Hanoi

The 3-peg version is well understood,and its time complexity is easilyprovable. The 4-peg version eluded mathematicians for over a century. In 1941, J.S. Frame and B.M. Stewartindependently proposed a particular way of solving the 4-peg puzzle, which is popularly known as theFrame–Stewart algorithm (see below). In 1994, Paul Stockmeyer calculated an approximate closed-formexpression for the optimal number of moves made by the Frame–Stewart algorithm. Very recently, RobertoDemontis (December 2018) proved that the Frame–Stewart algorithm is indeed optimal.

There are four pegsA,B,C,D(numbered as 0,1,2,3). Initially,ndisks of diameters 1,2,3,...,nare stackedon PegAin the sorted order (the smallest disk at the top, and the largest disk at the bottom). The three otherpegs are initially empty. Your task is to transfer thendisks from PegAto PegBtaking help from the othertwo pegs, using a sequence of moves. Each move transfers asinglediskdfrom Pegpto Pegq(p6=q),such that the following two conditions hold just before the movement: (i) Diskdmust be sitting at the topof Pegp, and (ii) Diskdis not allowed to be larger than the disk (if any) sitting on the top of Pegq.

If only three pegs are allowed, we know that the best (minimum) number of moves isT3(n) =2n−1, and astraightforward divide-and-conquer algorithm solves the 3-peg puzzle using exactly these many moves.Ifwe are allowed to use a fourth peg, the Frame–Stewart algorithm is used, which involves the following steps(also see the figure on the next page).

1. Ifn<=3, solve the problem directly.
2. Fix a value ofkin the range 16k6n.
3. Keep theklargest disks on PegA, and transfer the smallestn−kdisks from PegAto PegD.
4. Transfer the largestkdisks from PegAto PegBwithout disturbing the smallestn−kdisks alreadysitting on PegD. Since a larger disk can never be put on the top of a smaller disk, PegDis unusablein this part, that is, we solve the 3-peg Tower-of-Hanoi problem onkdisks.
5. Transfer the smallestn−kdisks from PegDto PegBwithout disturbing the largestkdisks on PegB.In this step, all the four pegs can be used.

T4(n) =T4(n−k)+T3(k)+T4(n−k) =2T4(n−k)+2^k−1.


functionToH3(i,j,p,q,r)to transfer Disksithroughjfrom Pegpto Pegqusing a third Pegr.

functionToH41(i,j,p,q,r,s)to transfer Disksithroughjfrom Pegpto Pegqusing thetwo other pegsrands. Here, you takek=⌊m/2⌋(wherem=j−i+1 as defined above). This is a naturalchoice of breaking the problem into two equal halves, but this choice turnsout to be quite poor.

functionToH42(i,j,p,q,r,s,k)to transfer Disksithroughjfrom Pegpto Pegqusingthe two other pegsrands. Here, we use afixedvalue ofkindependent of the sizem=j−i+1 of thesubproblem posed to the recursive invocation. Ifm6k, solve the problem using the 3-peg Tower-of-Hanoialgorithm. Otherwise, follow the Frame–Stewart algorithm.

It turns out that the optimal choice forkis{√2m}for a recursive call onmdisks, where{x}is theinteger nearest tox. As shown by Stockmeyer, this choice ofkleads toT4(n)≈√n2√2n. Write a functionToH43(i,j,p,q,r,s)to implement this optimal version, wherei,j,p,q,r,s(andm) are as explained above.
