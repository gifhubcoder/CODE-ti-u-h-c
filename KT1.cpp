// Bài 2 Lập trình nâng cao
// cài đặt cấu trúc dữ liệu cho danh sách liên kết  chứa dãy số nguyên theo kiểu con trỏ
// Lập 1 Menu để thực hiện:
// - Tạo danh sách
// - Thêm vào một phần tử bất kỳ
// - Thêm vào một phần tử bất kỳ cuối danh sách
// - Xóa một phần tử bất kỳ
// - Xóa một phần tử bấy kỳ ở cuối danh sách
// - Tìm kiếm
//------------------------------------------------------------------------------------------------//
#include <iostream>

using namespace std;

char input[100],output[100];

// Khởi tạo cấu trúc NODE
//------------------------------------------------------------------------------------------------//
struct node
{
    int data;
    struct node *pNext;
};
typedef struct node NODE;

// Khởi tạo node đầu và node cuối để quản lí
//------------------------------------------------------------------------------------------------//
struct list
{
    NODE *pHead; // node đầu
    NODE *pTail; // node cuối
};
typedef struct list LIST;

// khởi tạo cấu trúc của 1 list
//------------------------------------------------------------------------------------------------//
void khoitao(LIST &l)
{
    l.pHead = NULL; // con trỏ đầu 
    l.pTail = NULL; // con trỏ cuối
}

// Khởi tạo node
//------------------------------------------------------------------------------------------------//
NODE *KhoitaoNODE(int x)
{
    NODE *p = new NODE; // cấp phát ô nhớ cho 1 node
    p->data = x; 
    p->pNext = NULL; 
    return p;
}

// Hàm thêm vào đầu danh sách
//------------------------------------------------------------------------------------------------//
void themvaodau(LIST &l, NODE *p)
{
    if(l.pHead == NULL)
    {
        l.pHead = l.pTail = p;// nếu danh sách rỗng thì node đầu = node cuối và = p
    }
    else
    {
        p->pNext = l.pHead; // trỏ đến node đầu
        l.pHead = p; // và thay thế phần tử vừa nhập là node đầu
    }
}

// Hàm thêm vào cuối danh sách
//------------------------------------------------------------------------------------------------//
void themvaocuoi(LIST &l, NODE *p)
{
    if(l.pHead == NULL)
    {
        l.pHead = l.pTail = p; // nếu danh sách rỗng thì node đầu = node cuối và = p
    }
    else // ngược lại
    {
        l.pTail ->pNext = p; // trỏ tới node cuối
        l.pTail = p; // cập nhật lại node cuối
    }
}

// Hàm Thêm vào vị trí bất kì trong danh sách
//------------------------------------------------------------------------------------------------//
void themvaovitri(LIST &l, NODE *p, int vt, int n)
{
    if(l.pHead == NULL || vt == 1) // nếu danh sách rỗng thì thêm vào đầu 
    {
        themvaodau(l, p);
    }
    else if(vt == n + 1) // Nếu danh sách có 1 node thì thêm vào đằng sau
    {
        themvaocuoi(l, p);
    }
    else
    {
        int dem = 0;
        // Ngược lại thêm 1 node g liên kết giữa các node
        NODE *g = new NODE; // cấp phát bộ nhớ cho node g
        // duyệt từ đầu đến cuối
        for(NODE *k = l.pHead; k != NULL; k = k->pNext)
        {
            dem++;
            // tìm vị trí cần thêm
            if(dem == vt)
            {
                NODE *h = KhoitaoNODE(p->data);// mỗi lần phát hiện 1 node thì ta khởi tạo 1 node h mới <=> với node p cũ
                h->pNext = k; // đầu tiên là cho node h liên hết đến node k
                g->pNext = h; // tiếp theo cho node g liên kết đến node h và tạo thành 1 liên kết mới
                break; // dừng lại khi thực hiện xong
            }
            g = k;// giữ liên kết với node k trước
        }
    }
}

// Hàm xóa 1 node ở đầu
//------------------------------------------------------------------------------------------------//
void DeHead(LIST &l)
{
    if(l.pHead == NULL)
    {
        return;
    }
    NODE *p = l.pHead;// node p là node sẽ xóa
    l.pHead = l.pHead->pNext;// cập nhật node đầu là node tiếp theo
    delete p;
}

// Hàm xóa 1 node ở cuối
//------------------------------------------------------------------------------------------------//
void DeTail(LIST &l)
{
    if(l.pHead == NULL)
    {
        return;
    }
    for(NODE *k = l.pHead; k != NULL; k = k->pNext)// duyệt từ đầu đến cuối
    {
        // nếu phát hiện thằng kế cuối
        if(k->pNext == l.pTail)
        {
            delete l.pTail; // xóa node cuối
            k->pNext = NULL; // cho con trỏ trỏ tới node gần null
            l.pTail = k; // cập nhật lại node cuối
        }
    }
}

// Hàm xóa 1 node bất kì
//------------------------------------------------------------------------------------------------//
void DeAt(LIST &l, int vt)
{
    // nếu nodo cần xóa nằm đầu danh sách
    if(l.pHead->data == vt)
    {
        DeHead(l);
        return;
    }
    // nếu node cần xóa nằm cuối danh sách
    if(l.pTail->data == vt)
    {
        DeTail(l);
        return;
    }
    // ngược lại
    // Duyệt từ đầu đến cuối
    NODE *g = new NODE; // node g là node  trỏ đến node nằm trước node cần xóa : vt
    for(NODE *k = l.pHead; k != NULL; k = k->pNext)
    {
        if(k->data == vt)
        {
            g->pNext = k->pNext; // cập nhật liên kết
            delete k; // xóa đi node nằm ở vị trí cần xóa
            return;
        }
        g = k;// cho node g giữ liên kết giữa các node
    }
}

// Hàm tìm kiếm
//------------------------------------------------------------------------------------------------//
void Seach(LIST &l, int vt)
{
    int n = 0;
    if(l.pHead == NULL)
    {
        cout<<"Danh sach rong!";
        system("pause");
    }
    for(NODE *k = l.pHead; k != NULL; k = k->pNext)
    {
        n++;
        // duyệt từ đầu đến cuối
        if(k->data == vt)// nếu k = vt thì xuất kết quả
        {
           cout << "\tTim Thay: " << k->data<<endl;
           cout <<"\t Xuat hien tai vi tri: " <<n<<endl;
           system("pause");
        }
    }
    
}
// Hàm in node ra màn hình
//------------------------------------------------------------------------------------------------//
void xuat(LIST l)
{
    for(NODE *k = l.pHead; k != NULL;k = k->pNext)
    {
        cout <<" "<< k->data; // in các node được thêm vào danh sách ra màn hình
    }
    cout << "\n";
}

// Hàm Đọc dữ liệu từ file
//------------------------------------------------------------------------------------------------//
void Readfile(LIST &l)
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
        NODE *p = KhoitaoNODE(btg);
        themvaodau(l, p);
    }
    fclose(Fin);
}

// Hàm MENU chương trình
//------------------------------------------------------------------------------------------------//
void MENU(LIST &l)
{
    int chon,x;
    while (69)
    {
        system("cls");
        cout<< "\t\t\tMENU Lien Ket Don\n";
        cout<< "\t1.Them 1 node vao dau danh sach\n";  
        cout<< "\t3.Them 1 node vao cuoi danh sach\n";
        cout<< "\t2.Them 1 node vao vi tri bat ki trong dan sach\n";
        cout<< "\t4.Xuat danh sach \n";
        cout<< "\t5.Xoa 1 node dau danh sach\n";
        cout<< "\t6.Xoa 1 node cuoi danh sach\n";
        cout<< "\t7.Xoa 1 node tai vi tri bat ki trong danh sach\n";
        cout<< "\t8.Tim kiem trong danh sach\n";
        cout<< "\t9.Doc so lieu tu file vao\n";
        cout<< "\t---CODE BY: NHAN CODER---------------------------\n";
        cin >> chon;
        if(chon < 0 || chon > 10)
        {
            cout<<"\tlua chon khong hop le";
            system("pause");
        }
        if(chon == 1)
        {
            cout <<"\tNhap gia tri so nguyen";
            cin >> x;
            NODE *p = KhoitaoNODE(x);// Khởi tạo 1 cái node
            themvaodau(l, p); // Thêm vào đầu danh sách
        }
        else if(chon == 2)
        {
            cout <<"\tNhap gia tri so nguyen";
            cin >> x;
            NODE *p = KhoitaoNODE(x);// Khởi tạo 1 cái node
            themvaocuoi(l, p); // Thêm vào cuối danh sách
        }
        else if (chon == 3)
        {
            int n = 0; // biến lưu số lượng node trong danh sách
            // vòng lặp lấy số lượng danh sách
            for(NODE *k = l.pHead; k != NULL; k = k->pNext)
            {
                n++;
            }
            // Khởi tạo giá trị cho node p
            cout<<"\tNhap gia tri so nguyen";
            cin >> x;
            NODE *p = KhoitaoNODE(x);
            // tìm vị trí cần thêm vào
            int vt;
            do
            {
                cout<<"\t\nNhap vi tri can them";
                cin >> vt;
                if(vt < 1 || vt > n + 1) // kiểm tra nếu vt có trong danh sách
                {
                    cout<<"\tVi tri can them khong nam trong danh sach";
                    system("pause");
                }
            } while (vt < 1 || vt > n + 1); // nếu vt có trong danh sách thì thêm vào
                {
                    themvaovitri(l, p, vt, n); 
                }
        }
        else if (chon == 4)
        {
            cout<< "\tDanh sach lien ket vua nhap:\n";
            xuat(l);
            system("pause");
        }
        else if (chon == 5)
        {
            DeHead(l);
        }
        else if (chon == 6)
        {
            DeTail(l);
        }
        else if(chon == 7)
        {
            cout <<"\tNhap node can xoa";
            cin >> x;
            DeAt(l, x);
        }
        else if(chon == 8)
        {
            cout <<"\tNhap node can tim trong danh sach";
            cin >> x;
            Seach(l, x);
        }
        else if (chon == 9)
        {
            Readfile(l);
        }
        
    }
}

// chương trình chính
//------------------------------------------------------------------------------------------------//
int main()
{
    LIST l;
    khoitao(l);// luôn luôn gọi hàm khởi tạo danh sách trước khi thao tác
    MENU(l);
    system("pause");
    return 0;
}
