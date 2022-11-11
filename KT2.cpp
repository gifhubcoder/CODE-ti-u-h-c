// Bài Lập trình nâng cao 2
// Cài đặt cấu trúc hàng đợi QUEUE
// Yêu cầu:
// - Khởi tạo Queue
// - Thêm 1 phần tử vào cuối hàng đợi ( enQueue )
// - xóa phần tử đầu tiên trong hàng đợi ( deQueue )
// - lấy giá trị đầu tiên trong hàng đợi mà không xóa nó ( peekHeadQueue )
// - lấy giá trị cuối hàng đợi mà không xóa nó ( peekTailQueue )
// - kiểm tra xem hàng đợi có rỗng hay không ( isEmtyQueue )
// - Tính trung bình động
//------------------------------------------------------------------------------------------------//
// - Đầu vào
// - FILE input, output nhập từ bàn phím
// - Đầu ra
// - in số trung bình động đã được tính vào file output

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

char input[100],output[100];

// Khởi tạo liên kết đơn
//------------------------------------------------------------------------------------------------//
struct linkedlist
{
    int data;
    struct linkedlist *next;
};

typedef struct linkedlist *node; //tu gio dung kieu du lieu linkedlist co the thay bang node

// ham khoi tao mot node moi va gan gia tri cho no
//------------------------------------------------------------------------------------------------//
node Createnode(int value)
{
    node temp; // temp co kieu du lieu node
    temp = (node)malloc(sizeof(struct linkedlist));// cap phat vung nho dung malloc()
    temp -> next = NULL;// cho next tro toi null
    temp -> data = value;// gan gia tri cho node
    return temp;// tra va node moi da co gia tri
}

// ham them node vao cuoi hang doi
//------------------------------------------------------------------------------------------------//
node enQueue(node head, int value)
{
    node temp,p;// khia bao 2 node tam thoi temp va p
    temp = Createnode(value);// Goi ham createnode de khoi tao node temp co next tro toi null va gia tri value
    if (head == NULL)
    {
        head = temp;// neu linkedlist dang trong thi cho la head luon
    }
    // nguoc lai
    else
    {
        p = head;// khoi tao p tro toi head
        while (p->next != NULL)
        {
            p = p ->next;//duyet danh sach den cuoi. node cuoi la node co next = NULL
        }
        p ->next = temp;//gan next cua thang cuoi cung = temp. khi do temp se la thang cuoi cung (temp -> next = NULL ma) 
    }
    return head;
}

// tao ham xoa node la dau tien cua Queue
//------------------------------------------------------------------------------------------------//
node DelQueue(node head)
{
    if (head == NULL)// neu heal = null thi khong co gi de xoa
    {
        printf("\n Cha co gi de xoa het!");
    }
    // nguoc lai
    else
    {
        head = head->next;// neu co heal se duoc tro toi next
    }
    return head;// tra ve gia tri heal
}

// tao ham lay gia tri cua node dau tien
//------------------------------------------------------------------------------------------------//
int PeekHeadQueue(node head)
{
    return head ->data;//tra ve heal voi gia tri dang duco tro vao data dau tien 
}

// tao ham lay gia tri cua node cuoi cung
//------------------------------------------------------------------------------------------------//
int PeekTailQueue(node head)
{
    node p;// khoi tao kieu du lieu tam thoi node vao p
    p = head; //khoi tao p tro toi head
    //bat dau duyet tu dau den cuoi Queue, de dinh vi vao phan tu dung cuoi cung
    while (p ->next != NULL)
    {
        p = p ->next;//gan gia tri p bang gia tri p tro toi next co next = null
    }
    return p ->data;//p duoc gan gia tri la data
}

// tao ham khoi tao Queue
//------------------------------------------------------------------------------------------------//
node intiQueue()
{
    node head;// head co kieu du lieu node(linkedlist)
    head = NULL;//heal = rong thi tra lai gia tri la head
    return head;
}

//phan chinh cua chuong trinh
//------------------------------------------------------------------------------------------------//
int main() 
{
    FILE *Fin,*Fout;
    static int a[10000],n,k,sum,i=0;
    float tbd[1000],cnt;//bien luu tru day gia tri trung binh dong
    cout <<"|-------------------------------------------------------------------------|"<<endl;
    cout <<"|                 Hang Doi Queue de tinh trung binh dong                  |"<<endl;
    cout <<"|                         CODE BY: NHAN CODER                            |"<<endl;
    cout <<"|-------------------------------------------------------------------------|"<<endl;
    cout <<"\tMoi ban nhap file vao "; gets(input);
    cout <<"\tMoi ban nhap file ra "; gets(output);
    Fin = fopen(input,"r");
    if(Fin == NULL)
    {
        printf("Mo file that bai!");
        exit(1);//thoat khi mo file khong thanh cong
    }
    int btg;
    while (fscanf(Fin,"%d",&btg) != EOF)
    {
        a[n]=btg;//gan a[n] = btg de lay gia tri tu file ra su dung
        printf("%8d",a[n]);
        n++;//moi mot lan lap n se cong len 1
    }
    fclose(Fin);
    //tinh trung binh dong
    // khoi tao Queue
    node head = intiQueue();
    printf("\n Nhap Bac Tinh Trung Binh Dong K="); scanf("%d",&k);
    // them cac phan tu vao hang doi Queue
    for(i=0;i<k;i++)
    {
        sum += a[i];
        head = enQueue(head, a[i]);
    }
    printf("\n Day Trung Binh Dong Voi K = %d",k);
    //in day so vua dua vao hang doi Queue
    for(i=0;i<k;i++)
    {
        printf("%8d",a[i]);
        if(i%4) printf("\n");
    } 
    for(i = k; i < n; i++)
    {
        cnt = tbd[i-k] = (float)sum/k;//dinh dang kieu float cho day so moi(gia tri trung binh)
        sum = sum - PeekHeadQueue(head);//Bo gia tri cua phan tu dau tien khoi sum
        head = DelQueue(head);//Loai bo phan tu dau tien khoi Queue
        head = enQueue(head,a[i]);//them phan tu vao hang doi Queue
        sum += PeekTailQueue(head);//cong gia tri vua duoc them vao sum
        printf("%10.2f",cnt);//in ket qua
    }
    printf("\nDONE!");
    Fout = fopen(output,"w");
    if(Fout == NULL)
    {
        printf("Mo Flie that bai");
        exit(1);
    }
    fprintf(Fout,"|-------------------------------------------------------------------------|\n");
     fprintf(Fout,"|                 Hang Doi Queue de tinh trung binh dong                  |\n");
      fprintf(Fout,"|                         CODE BY: NHAN CODER                            |\n");
       fprintf(Fout,"|-------------------------------------------------------------------------|\n");
        fprintf(Fout,"Bac tinh trung binh cong k = %d\n",k);
        fprintf(Fout,"Day Trung Binh Dong Voi K = %d\n",k);
    //in day so vua dua vao hang doi Queue
    for(i=0;i<k;i++)
    {
        fprintf(Fout,"%8d",a[i]);
        if(i%4) fprintf(Fout,"\n");
    }
    fprintf(Fout,"\n");
    //in ket qua
    for(i = k; i < n; i++)
    {
        cnt = tbd[i-k];
        fprintf(Fout,"%10.2f",cnt);
        if(i%4) fprintf(Fout,"\n");
    }
    fclose(Fout);
}