/* Generated by Frama-C */
/*@ requires 2 <= n <= 10000 && \valid(t + (0 .. n - 1));
    ensures
      \forall integer __q_j;
        0 <= __q_j < \old(n) ==>
        (*(\old(t) + __q_j) != 0 <==>
         __q_j >= 2 &&
         (\forall integer __q_l; 2 <= __q_l < __q_j ==> __q_j % __q_l != 0));
    typically n < 5;
    assigns *(t + (0 .. n - 1));
 */
void find_primes(int *t, int n)
{
  int i;
  int k;
  i = 2;
  *(t + 0) = 0;
  *(t + 1) = 0;
  loop_1:
    /*@ loop invariant i1: 2 <= i <= n;
        loop invariant
          i2:
            \forall integer __q_j;
              0 <= __q_j < i ==>
              (*(t + __q_j) != 0 <==>
               __q_j >= 2 &&
               (\forall integer __q_l;
                  2 <= __q_l < __q_j ==> __q_j % __q_l != 0));
        loop assigns i, k, *(t + (0 .. n - 1));
        loop variant n - i;
    */
    while (i < n) {
      k = 2;
      *(t + i) = 1;
      loop_2:
        /*@ loop invariant i3: 2 <= k <= i;
            loop invariant
              i4:
                \forall integer __q_j;
                  0 <= __q_j < i ==>
                  (*(t + __q_j) != 0 <==>
                   __q_j >= 2 &&
                   (\forall integer __q_l;
                      2 <= __q_l < __q_j ==> __q_j % __q_l != 0));
            loop invariant
              i5: \forall integer __q_l; 2 <= __q_l < k ==> i % __q_l != 0;
            loop invariant i6: *(t + i) == 1;
            loop assigns k, *(t + (0 .. i));
            loop variant i - k;
        */
        while (k < i) {
          if (i * k == 0) {
            *(t + i) = 0;
            break;
          }
          k ++;
        }
      i ++;
    }
  return;
}

