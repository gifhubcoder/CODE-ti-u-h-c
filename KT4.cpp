// Bài 4 lập trình nâng cao
// cài đặt cấu trúc dữ liệu mảng băm
//------------------------------------------------------------------------------------------------//
// Yêu cầu
// - Khởi tạo Bảng băm
// - Hashfunct (): hàm có chức năng tính toán chỉ số băm
// - Insert (): chèn thêm một phần tử vào bảng băm
// - Remove (): loại một phần tử trong bảng băm
// - Clear(): xóa tất cả các phần tử trong bảng băm
// - Traver (): in ra giá trị của tất cả các phần tử trong bảng băm
// - Search (): Tìm kiếm một giá trị trả về có hay không.
// - Traverser(): In ra giá trị của các phần tử trong danh sách
//------------------------------------------------------------------------------------------------//
// Lập một menu để thực hiện các công việc sau
// - Thêm một nút vào bảng băm
// - Xóa một nút trong bảng băm
// - Xóa toàn bộ bảng băm
// - Duyệt bảng băm
// - Tìm kiếm
//------------------------------------------------------------------------------------------------//

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define M 10 

using namespace std;

char input[100],output[100];

// Khởi tạo cấu trúc NODE
//------------------------------------------------------------------------------------------------//
struct node
{
    int data;
    struct node *pNext;
};
typedef struct node *NODE;

// Hàm tạo một nút và gán giá trị cho nó
//------------------------------------------------------------------------------------------------//
 NODE cratenode(int value)
 {
    NODE p;
    p = (NODE)malloc(sizeof(struct node)); // cấp phát vùng nhớ
    p->data = value; // gán giá trị 
    p->pNext = NULL; // trỏ tới bộ nhớ rỗng
    return p; // trả về kết quả
 }

 // khởi tạo bảng băm
 //------------------------------------------------------------------------------------------------//
 NODE Bucket[M]; // có giá trị là 10 bảng băm

 // Tạo hàm băm
 // tạo khóa key là giá trị cần băm
 // trả về chỉ số của bảng băm
 //------------------------------------------------------------------------------------------------//
 int HashFunc(int key)
 {
    return (key % M); // giá trị của key là từ 1 đến M
 }

 // Khởi tạo các Bucket ban đầu = null
 //------------------------------------------------------------------------------------------------//
 void InitBucket()
 {
    for(int b = 0; b < M; b++)
    {
        Bucket[b] = NULL; // các bucket ban đầu đều đc gán = null
    }
 }

 // Kiểm tra bucket có rỗng hay không
 //------------------------------------------------------------------------------------------------//
void IsEmtybucket(int b)
{
    if(Bucket[b] == NULL)
        cout <<"\t bang bam rong";
    else
        cout <<"\t bang bam co " << Bucket[M] <<"Phan tu";
}

// hàm chèn  một nút có giá trị là k vào bảng băm
//------------------------------------------------------------------------------------------------//
void Insert(int k)
{
    int b = HashFunc(k);
    NODE p,q = NULL; // tạo 2 con trỏ p , q để duyệt DSLK
    // q là con trỏ trước , p la con trỏ sau
    for(p = Bucket[b]; p != NULL && k > p->data; p = p->pNext)
        q = p;
        // Thêm vào đầu bucket
        if(q == NULL)
        {
            NODE g = cratenode(k); // khởi tạo cấu trúc của 1 node mới ở đầu
            g->pNext = Bucket[b]; // cho node trỏ đến bảng băm
            Bucket[b] = g; // cập nhật giá trị cho node
        }
        else
            // Nút cuối cùng của  bucket
            if(p == NULL)
            {
                NODE g = cratenode(k); // tạo cấu trúc của 1 node mới ở cuối
                q->pNext = g; // cập nhật giá trị cho node ở cuối
            }
            else
            // nút giữa của bucket
            {
                NODE g = cratenode(k);// tạo cấu trúc của 1 node ở giữa
                g->pNext = q->pNext; // cho giá trị được trỏ đến = nút tiếp theo trước nút đầu
                q->pNext = g; // cập nhật giá trị nút 
            }
    return;
}

// Hàm xóa 1 nút có khóa k
//------------------------------------------------------------------------------------------------//
void Remove(int k)
{
    // đầu tiên là lấy địa trỉ bucket
    int b = HashFunc(k); // b được gán là các khóa
    NODE p = Bucket[b], q = Bucket[b]; // 2 con trỏ p , q để duyệt danh sách liên kết
    // tiếp theo tìm vị trí có nút chứ k
    for(p = Bucket[b]; p != NULL && p->data != k; p = p->pNext)
       q = p;
       // nếu duyệt hết danh sách mà không có 
       if(p == NULL)
       {
        cout << "\tKhong co nut khoa :"<<k;
       }
       else if (p == Bucket[b]) // nếu có
       {
        Bucket[b] = p->pNext; // khóa tiếp theo sẽ là khóa đầu và giải phóng khóa trước
        free(p); // giải phóng p
       }
       else // ngược lại
       {
        q->pNext = p->pNext; // nút kế tiếp sẽ là nút được liên kết
        free(p); // và giải phóng nút trước nó
       }
}

// Xóa toàn bộ nút trong 1 bucket b
//------------------------------------------------------------------------------------------------//
void ClearBruket(int b)
{
    NODE p = Bucket[b], q = NULL; // q là nút đầu . p là nút cuối
    // tạo một vòng lặp để xóa từ đầu đến cuối
    while(p != NULL)
    {
        q = p; // cho đầu  = cuối
        p = p->pNext; // và con trỏ trỏ đến phần tử tiếp theo
        free(q); // giải phóng phần tử trước đó
    }
    Bucket[b] = NULL; // khởi tạo lại bucket rỗng
}

// Hàm xóa toàn bộ nút trong bảng băm
//------------------------------------------------------------------------------------------------//
void clear()
{
    // tạo 1 vòng lặp xóa từ đầu đến cuối
    for(int b = 0; b < M; b++)
        ClearBruket(b);
}

// Hàm duyệt một bucket b
//------------------------------------------------------------------------------------------------//
void TraverseBucket(int b)
{
    NODE p = Bucket[b]; // 1 nút p có khóa b
    // một vòng lặp để duyệt từ đầu đến cuối
    while(p != NULL)
    {
        cout <<"\t\t" <<p->data; // in ra các nút có trong 1 bucket
        p = p->pNext; // cập nhật sau mỗi lần lặp để in ra màn hình
    }
}

// Hàm duyệt bảng băm
//------------------------------------------------------------------------------------------------//
void Traverse()
{
    // tạo 1 vòng lặp để duyệt các khóa b
    for(int b = 0; b < M; b++)
    {
        cout <<"\t\t\nBucket :" << b ;
        TraverseBucket(b);
    }
    cout <<"\n";
}

// hàm tìm kiếm một giá trị k trong bảng băm
// nếu thấy trả về 1
// không thấy trả về -1
//------------------------------------------------------------------------------------------------//
int Seach(int k)
{
    // lấy chỉ số của bảng băm cũng là chỉ số của bucket
    int b = HashFunc(k);
    NODE p = Bucket[b];
    // một vòng lặp để duyệt từ p đầu đến p trỏ tới cuối (null)
    while (k > p->data && p != NULL)
        p = p->pNext; // cập nhật con trỏ sau mỗi vòng lặp
        if(p == NULL || k != p->data) // khong tim thay hoac k có trong bảng băm
            return -1;
        else
            return 1;
}

// Hàm đọc dữ liệu vào từ file
//------------------------------------------------------------------------------------------------//
void Readfile()
{
    FILE *Fin;
    cout << "\tNhap file vao"; 
    cin >> input;
    Fin = fopen(input,"r");
    if(Fin == NULL)
    {
        printf("Mo file that bai!");
        exit(1);//thoat khi mo file khong thanh cong
    }
    int btg;
    while (fscanf(Fin,"%d",&btg) != EOF)
    {
       Insert(btg);
    }
    fclose(Fin);
}

// TẠO 1 MENU
//------------------------------------------------------------------------------------------------//
void MENU()
{
    int chon,x,b,i,n;
    char c;
    while (69)
    {
        system("cls");
        cout<< "\t\t\tMENU Bang bam\n";
        cout<< "\t1.Them 1 node vao bang bam\n";  
        cout<< "\t2.Xoa nut trong bang bam\n";
        cout<< "\t3.Xoa toan bo bang bam\n";
        cout<< "\t4.Duyet bang bam \n";
        cout<< "\t5.Tim kiem trong bang bam\n";
        cout<< "\t6.Doc so lieu tu file vao\n";
        cout<< "\t---CODE BY: NHAN CODER---------------------------\n";
        cin >> chon;
        if(chon == 1)
        {
            cout<< "\t1.Them 1 node vao bang bam\n";
            cout<< "\tKhoa cua nut moi: "; cin >> x;
            Insert(x);
            system("\n\tpause");
        }
        else if(chon == 2)
        {
            cout<< "\t2.Xoa nut trong bang bam\n";
            cout<< "\tKhoa cua nut can xoa: "; cin >> x;
            Remove(x);
            system("\n\tpause");
        }
        else if(chon == 3)
        {
            cout<< "\t3.Xoa toan bo bang bam\n";
            cout<< "\tBan co chac khong!";
            c = getch();
            if(c == 'c' || c == 'C')
                clear();
            system("\n\tpause");
        }
        else if (chon == 4)
        {
             cout<< "\t4.Duyet bang bam \n";
             Traverse();
             system("\n\tpause");
        }
        else if(chon == 5)
        {
            cout<< "\t5.Tim kiem trong bang bam\n";
            cout<< "\tkhoa can tim:"; cin >> x;
                if(Seach(x) == -1)
                   {
                    cout<<"\tKhong tim thay hoac khong co trong bang bam"<<endl;
                    system("\n\tpause");
                   }
                else
                    {
                    cout<<"\tTim thay trong bucket: " << HashFunc(x)<<endl;
                    system("\n\tpause");
                    }
        }
        else if(chon == 6)
        {
            Readfile();
        }
    }
}

// Chương trình chính
//------------------------------------------------------------------------------------------------//
int main()
{
    InitBucket();
    MENU();
    return 0;
}
