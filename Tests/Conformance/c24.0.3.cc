/* Conformance Test 24.0.3:  Test the use of the extended character set  */

#pragma lint -1

#include <stdio.h>
#include <string.h>

typedef enum {false, true} boolean;

void main (void)

{
boolean fail;
int a, b, c, i;
char str[128];

int �����������ą�����Ƈ������؉�������ˌ��̍��͎����ޏ�����;
int �����������ą�����Ƈ���˘�؉�����ͻˁ��̂��̓����ޏ�����;

/* Make sure alpha-"looking" characters are allowed in identifiers,
   and that the lowercase versions are distinct from the uppercase
   versions. */
fail = false;
   �����������ą�����Ƈ������؉�������ˌ��̍��͎����ޏ����� = 4;
   �����������ą�����Ƈ���˘�؉�����ͻˁ��̂��̓����ޏ����� = 5;
if (�����������ą�����Ƈ������؉�������ˌ��̍��͎����ޏ����� != 4)
   fail = true;

/* Make sure all special characters are allowed in strings */
strcpy(str, "");
for (i = 17; i <= 20; ++i)
   if (str[i - 17] != i) {
      fail = true;
      printf("Character %d was incorrect in str.\n", i);
      }
strcpy(str, "��������������������������������������������"
            "���������������������������������������������");
for (i = 128; i <= 216; ++i)
   if (str[i - 128] != i) {
      fail = true;
      printf("Character %d was incorrect in str.\n", i);
      }
if ('�' != 222) {
   fail = true;
   printf("Character 222 was incorrect in str.\n");
   }
if ('�' != 223) {
   fail = true;
   printf("Character 223 was incorrect in str.\n");
   }

/* Make sure all special characters are allowed in comments */
/* The special character set is:

   0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F

0           0  @  P  `  p  �  �  �  �  �  �
1       !  1  A  Q  a  q  �  �  �  �  �  �
2       "  2  B  R  b  r  �  �  �  �  �  �
3       #  3  C  S  c  s  �  �  �  �  �  �
4       $  4  D  T  d  t  �  �  �  �  �  �
5        %  5  E  U  e  u  �  �  �  �  �  �
6        &  6  F  V  f  v  �  �  �  �  �  �
7        '  7  G  W  g  w  �  �  �  �  �  �
8        (  8  H  X  h  x  �  �  �  �  �  �
9        )  9  I  Y  i  y  �  �  �  �  �
A        *  0  J  Z  j  z  �  �  �  �  �
B        +  :  K  [  k  {  �  �  �  �  �
C        ,  ;  L  \  l  |  �  �  �  �  �
D        _  <  M  ]  m  }  �  �  �  �  �
E        .  =  N  ^  n  ~  �  �  �  �  �  �
F        /  ?  O  _  o     �  �  �  �  �  �
*/

/* Make sure the special operators work */
/* Some lines also test the non-breaking space */
a�=�100;
b�=�3;
c�=�a�b;
if�(aʲ�b)
   fail = true;
if (! (a � a))
   fail = true;
if (b � a)
   fail = true;
if (! (b � b))
   fail = true;
if (c � 33)
   fail = true;
c = a � 2;
if (c � 400)
   fail = true;
c = a � 2;
if (c � 25)
   fail = true;

if (!fail)
   printf("Passed Conformance Test 24.0.3\n");
else
   printf("Failed Conformance Test 24.0.3\n");
}
