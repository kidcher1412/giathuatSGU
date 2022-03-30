package DoThi.src;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

public class LThong_VH {
    public int matrix[][];
    public int topNum(){
        return (this.matrix != null) ? this.matrix.length : 0;}
    public void tpLThong() {
        //Khởi tạo biến đếm thành phần liên thông
        int dem = 1;
        int i = 0;
        int numVertex = topNum();
        ArrayList listVS = new ArrayList();
        int visit[] = new int[numVertex];
        Stack stack = new Stack();
        
        //setTop dùng để chứa các đỉnh chưa duyệt, đỉnh nào chưa duyệt thì qua đỉnh đó để duyệt
        ArrayList setTop = new ArrayList<>();
        //chứa tất cả các đỉnh
        for(int j = 0; j < topNum(); j++) {
            setTop.add(j);
        }
        listVS.add(i);
        visit[i] = 1;
        stack.push(i);
        //mỗi lần duyệt rồi thì xóa đỉnh đó trong setTop
        setTop.remove(i);
        
        while (!stack.empty()) {
            i = (int) stack.peek();
            int count = 0;
            for (int j = 0; j < visit.length; j++) {
                if ((this.matrix[i][j] > 0) && visit[j] != 1) {
                    visit[j] = 1;
                    listVS.add(j);
                    stack.push(j);
                    //đã duyệt thì xóa trong setTop,vì j là giá trị,nên cần 
                 //tim index của giá trị này để xóa trong setTop.
                    for (int j2 = 0; j2 < setTop.size(); j2++) {
                        if ((int)setTop.get(j2) == j)
                            setTop.remove(j2);
                    }
                    break;
                } else {
                    count++;
                }
            }
            if (count == visit.length) {
            //Nếu đã không có cạnh để đi thì in ra thành phần liên thông và đường đi
                System.out.println("Thanh phan lien thong thu: " + dem);
                print(listVS);
                //Sau đó, kiểm tra đỉnh nào chưa duyệt thì duyệt tiếp.Vì setTop chứa những đỉnh 
                //chưa duyệt, nên chỉ cần lấy đỉnh đầu tiên trong setTop
                //Nếu setTop rỗng nghĩa là đã đi qua hết rồi thì dừng chương trình
                if (!setTop.isEmpty()) {
                    i = (int) setTop.get(0);
                    //Khi lấy ra rồi thì tăng biến đếm thành phần liên thông lên
                    dem++;
                    //KHi bắt đầu quá trình mới thì nhớ xóa hết stack với cái list đỉnh đã đi qua
                    stack.removeAll(stack);
                    //push lại giá trị vừa lấy ra từ setTop, nếu không chương trình dừng vì stack rỗng
                    stack.push(i);
                    listVS.removeAll(listVS);
                } else {
                    //nếu setTop rỗng thì dừng 
                    break;
                }
 
            }
        }
    }
    public void enterMatrix() {
		System.out.print("Moi nhap co cua ma tran: ");
		Scanner scan = new Scanner(System.in);
		int m = scan.nextInt();
		matrix = new int[m][m];
		for (int i = 0; i < matrix.length; i++) {
			for (int j = 0; j < matrix.length; j++) {
//				matrixA[i][j] = new int;
				System.out.println("matrixA["+i+"]["+j+"]= ");
				matrix[i][j] = scan.nextInt();
			}
			System.out.println();
		}
	}
    public void print(final ArrayList list) {
        for (int i = 0; i < list.size(); i++) {
            System.out.print(list.get(i) + " ");
        }
        System.out.print("\n");
    }
    public static void main(final String[] args){
        final LThong_VH l = new LThong_VH();
        l.enterMatrix();
        l.tpLThong();
    }
}
