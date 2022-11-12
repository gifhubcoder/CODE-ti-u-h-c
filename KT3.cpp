// Bài 3 Lập trình nâng cao
// Cài đặt cấu trúc dữ liệu stack
//------------------------------------------------------------------------------------------------//
// Yêu cầu
// - Khởi tạo STACK
// - Push(): đẩy 1 phần tử vào STACK
// - Pop(): lấy 1 phần tử ra khỏi STACK
// - PeekStack(): lấy giá trị của phần tử đầu STACK mà không loại bỏ nó
// - isEmptyStack(): kiểm tra xem stack có rỗng không
//------------------------------------------------------------------------------------------------//
// - Áp dụng STACK trên để giải bài toán đổi một dãy số nguyên dạng thập phân trong file input.txt sang dạng HEXA ( hệ 16), kết quả để vào file output.txt.
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Linkerlist
{
    int data;
    struct Linkerlist  *next;
};

typedef struct Linkerlist *node;

// Khoi tao mot node moi va gan gia tri cho no
//------------------------------------------------------------------------------------------------//
node newNode(int value)
{
    node temp;// bien temp theo kieu node
    temp = (node)malloc(sizeof(struct Linkerlist));// cap phat vung nho dung malloc()
    temp->next = NULL;// ch next tro toi null
    temp->data = value;// gan gia tri cho node
    return temp;// tra ve gia tri da duoc gan
}

// them mot node vao dau danh sach
//------------------------------------------------------------------------------------------------//
node Push(node head, int value)
{
    node temp;// bien temp theo kieu node
    temp = newNode(value);// khoi tao temp voi data = value
    if(head == NULL)
    {
        head = temp;// neu node dang trong thi node se = head
    }
    else
    {
        temp ->next = head;// tro toi next va gan gia tri = head
        head = temp;// doi head = temp vua duoc tro toi
    }
    return head;// tra gia tri da duoc gan
}

// Xoa node dau tien
//------------------------------------------------------------------------------------------------//
node Pop(node head)
{
    if(head == NULL)
    {
        std::cout << "Khong co gia tri de xoa" << std::endl;
    }
    else
    {
        head = head->next;//head duoc gan gia tri khi head tro toi next
    }
    return head;// tra ve gia tri da duoc gan
}

// Ham lay gia tri cua mot nut bat ki
//------------------------------------------------------------------------------------------------//
int peekstack(node head)
{
    return head->data;// tra ve gia tri head khi duoc tro den data
}

// Ham kiem tra xem stack co rong khong
//------------------------------------------------------------------------------------------------//
int isEmptystack(node head)
{
    if(head == NULL)
        return 1;// neu head khong tro ve gia tri gi thi tra ve ket qua la 1(rong)
    else
        return 0;// co gia tri thi tra ve 0
}

// Ham khoi tao stack
//------------------------------------------------------------------------------------------------//
node initstack()
{
    node head;//bien kieu node
    head = NULL;// neu chua co gi thi head se = null
    return head;// tra ve head duoc gan gia tri
}

// Ham chuyen doi so thap phan sang nhi phan
//------------------------------------------------------------------------------------------------//
int Chuyendoinhiphan(int n, int b)
{
    node head;
    head = initstack();// khoi tao stack
      if(n < 0 || b > 2 )
    {
        printf("He co so hoac gia tri chuyen doi khong hop le");
        return 0;
    }
    else
    {
        while (n != 0)
        {
            head = Push(head, n % b);// Nap phan tu cho stack sau moi vong lap
            n = (int) n / b; //chia lan tiep theo
        }
        // bat dau lay so stack ra cho den khi stack rong thi dung lai
        while (!isEmptystack(head))
        {
            printf("%d",peekstack(head));// lay gia tri o dau stack sau moi vong lap
            head = Pop(head);// xoa gia tri sau khi da lay
        } 
    }
}

// Ham chuyen doi so thap phan sang he 16( hexa )
//------------------------------------------------------------------------------------------------//
int chuyendoihe16(int n, int b)
{
    node head;
    head  = initstack();// Khoi tao stack
    if(n < 0 || b > 16)
    {
        printf("He co so hoac gia tri chuyen doi khong hop le");
        return 0;
    }
    else
    {
        while (n != 0)
        {
            head = Push(head, n % b);
            n = (int) n / b;
        }
        while (!isEmptystack(head))
        {
            int a = peekstack(head);// gan a lan luot  la cac gia tri lay trong stack vua duoc them
            head = Pop(head);// xoa gia tri sau khi da lay
            printf("%c","0123456789ABCDEF"[a]);// doi xung a lan luot voi hex
        }
    }
}

// Ham doc va su ly roi ghi vao file
//------------------------------------------------------------------------------------------------//
node readfile()
{
    FILE *f1,*f2,*f3;
    int num,n;
    f1 = fopen("d:\\code\\codeC++\\BTvecontro\\filesaver\\10.txt","r");
    if(f1 == NULL)
    {
        cout << "File khong ton tai!"; exit(1);
    }
    f2 = fopen("d:\\code\\codeC++\\BTvecontro\\filesaver\\test.txt","w");
    if(f2 == NULL || f3 == NULL)
    {
         cout << "File khong ton tai!"; exit(1);
    }
    while (fscanf(f1,"%d",&num) != EOF)
    {
    node head;
    head = initstack();// khoi tao stack
       if(num < 0)
    {
        printf("He co so hoac gia tri chuyen doi khong hop le");
        return 0;
    }
    else
        fprintf(f2,"\nHe so hex(16) la: ");
           while (num != 0)
        {
            head = Push(head, num % 16);// Nap phan tu cho stack sau moi vong lap
            num = (int) num / 16; //chia lan tiep theo
        }
        // bat dau lay so stack ra cho den khi stack rong thi dung lai
        while (!isEmptystack(head))
        {
            int a = peekstack(head);// gan a lan luot  la cac gia tri lay trong stack vua duoc them
            head = Pop(head);// xoa gia tri sau khi da lay
            fprintf(f2,"%c","0123456789ABCDEF"[a]);// doi xung a lan luot voi hex
        }
    }
    fclose(f1);
    f1 = fopen("d:\\code\\codeC++\\BTvecontro\\filesaver\\10.txt","r");
    if(f1 == NULL)
    {
        cout << "File khong ton tai!"; exit(1);
    }
     while (fscanf(f1,"%d",&n) != EOF)
    {
    node head;
    head = initstack();// khoi tao stack
       if(n < 0)
    {
        printf("He co so hoac gia tri chuyen doi khong hop le");
        return 0;
    }
    else
        fprintf(f2,"\nSo Nhi Phan La: ");
        while (n != 0)
        {
            head = Push(head, n % 2);// Nap phan tu cho stack sau moi vong lap
            n = (int) n / 2; //chia lan tiep theo
        }
        // bat dau lay so stack ra cho den khi stack rong thi dung lai
        while (!isEmptystack(head))
        {
            int b = peekstack(head);
            fprintf(f2,"%d",b);// lay gia tri o dau stack sau moi vong lap
            head = Pop(head);// xoa gia tri sau khi da lay
        } 
    }
    fclose(f1);
    fclose(f2);
}

// Chuong trinh chinh3
//------------------------------------------------------------------------------------------------//
int main()
{
    while (true)
    {
        std::cout << "|------------------STACK------------------|" << std::endl;
        std::cout << "| 1.Chuyen Doi so thap phan sang nhi phan |" << std::endl;
        std::cout << "| 2.Chuyen Doi So Thap Phan sang he hexa  |" << std::endl;
        std::cout << "| 3.Chuyen Doi va ghi vao file text       |" << std::endl;
        std::cout << "|       CODE BY: NHANCODER                |" << std::endl;
        std::cout << "|------------------STACK------------------|" << std::endl;
        int c,n;
        std::cout << "Moi Ban Nhap Muc Muon Thuc Hien" << std::endl; cin>>c;
         switch (c)
        {
        case 1:
                std::cout << "|------------------STACK------------------|" << std::endl;
                std::cout << "| 1.Chuyen Doi so thap phan sang nhi phan |" << std::endl;
                std::cout << "|------------------STACK------------------|" << std::endl;
                cout << "Nhap Vao So Nguyen N = "; cin >> n;
                printf("\nSo Nhi Phan La: ");
                Chuyendoinhiphan(n,2);
                printf("\nDONE\n");
            break;
        case 2:
                std::cout << "|------------------STACK------------------|" << std::endl;
                std::cout << "| 2.Chuyen Doi So Thap Phan sang he hexa  |" << std::endl;
                std::cout << "|------------------STACK------------------|" << std::endl;
                cout << "Nhap Vao So Nguyen N = "; cin >> n;
                printf("\nHe so hex(16) la: ");
                chuyendoihe16(n,16);
                printf("\nDONE\n");
            break;
        case 3:
                std::cout << "|------------------STACK------------------|" << std::endl;
                std::cout << "| 3.Chuyen Doi va ghi vao file text       |" << std::endl;
                std::cout << "|------------------STACK------------------|" << std::endl;
                readfile();
                printf("\nDONE\n");
            break;
        default:

            break;
        }
    }
}