"maze[2][101][101]"一個2層高，101*101的迷宮
"x,y,z"迷宮座標
"Rx,Ry,Rz"Romeo在迷宮的座標
"Jx,Jy,Jz"Juliet在迷宮的座標
"round"第幾回
"Rstep,Jstep"stack的計數
"Rstack[10201][4],Jstack[10201][4]"儲存Romeo和Juliet走過的位置，stack[step][0]為x、stack[step][1]為y、stack[step][2]為z、stack[step][3]為走的方向Romeo:1為右2為下3為上4為左Juliet:1為左2為上3為下4為右
"Rroad[2][101][101],Jroad[2][101][101]"確認Romeo和Juliet在退回之前是否走過此格
"line"輸入每行的資料
"*ptr"進行切字
"word[2]"該字為何

先輸入x，當它為1時將x設為0，當它為2時將x設為1，從y=0開始，每行讀入資料之後從z=0開始每次切一個字母或符號"X . o"，將代表"X . o"的數字存入maze[x][y][z]中，每切完一字z+1，當存完101個數字後y+1，z歸0一直到z=101且y=101時在輸入一次x。當輸入的x為2且y,z=101時開始走迷宮。

將"x,y,z"歸0，"Rstep,Jstep"設為0，round設為0，Rx設為0,Ry設為1,Rz設為1,Jx設為1,Jy設為99,Jz設為99(Romeo從(0,1,1),Juliet從(1,99,99)開始走)。
將Romeo和Juliet的位置存進Rstack,Jstack，Rroad[0][1][1]和Jroad[1][99][99]設為1代表走過這點。
接下來直到Romeo走到(1,99,99)或Juliet走到(0,1,1)或兩人中途相遇，不然一直重複下面括弧內步驟
(round+1，Romeo先確認右邊一格不為0(X)且此格沒有往右走過(Rstack[Rstep][3]!=1)且走的位置不為前一個位置且此位置沒走過，若全都符合將Rstack[Rstep][3]設為1，Rstep+1，儲存走後的位置進Rstack[Rstep]，將新位置的Rroad設為1。若不符合則判斷往下走一格是否成立，依序往上往左判斷，若四者皆不成立則Romeo往回走一格(將該點的Rstack[Rstep][3]設為0，Rroad設為0，Rstep-1後將該Rstack[Rstep]的迷宮座標位置存進Rx,Ry,Rz)，接下來若該迷宮座標點為傳送門且Romeo沒被傳送過，將其傳送到二樓，Rstack清空後將新座標存入Rstack[0]。判斷Romeo和Juliet是否相遇，若有則印出第幾回和Romeo現在的位置後跳出迴圈，若否則判斷Juliet的走位，依序為左上下右，方法跟Romeo相同後印出第幾回和Romeo及Juliet現在的位置，接下來判斷是否相遇，若是則跳出迴圈，若否則繼續迴圈)結束後若相遇則印"They encounter each other in (相遇座標)"，否則印出"They do not encounter each other in this maze."
