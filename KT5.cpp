// Bài 5 Lập trình nâng cao
// Cài đặt cấu trúc dữ liệu stack
//------------------------------------------------------------------------------------------------//
// Yêu cầu
// - Khởi tạo STACK
// - Push(): đẩy 1 phần tử vào STACK
// - Pop(): lấy 1 phần tử ra khỏi STACK
// - PeekStack(): lấy giá trị của phần tử đầu STACK mà không loại bỏ nó
// - isEmptyStack(): kiểm tra xem stack có rỗng không
//------------------------------------------------------------------------------------------------//
// Cho một xâu s gồm toàn các dấu ngoặc đóng và mở thuộc ba loại: (), [] và {}. Xâu s
// được gọi là xâu ngoặc đúng nếu như:
// - Số lượng ngoặc đóng bằng số lượng ngoặc mở mỗi loại.
// - Tại mọi vị trí của xâu s,s, số lượng đóng mỗi loại không vượt quá số lượng ngoặc mở của
// loại tương ứng.
// Hãy kiểm tra xâu s có phải là một xâu ngoặc đúng hay không?
//------------------------------------------------------------------------------------------------//
// - Nếu si là dấu ngoặc mở thì push vào stack.
// - Nếu si là dấu ngoặc đóng, ta kiểm tra xem dấu ngoặc ở đỉnh của stack có phải ngoặc mở cùng loại
// không, nếu đúng thì loại bỏ dấu ngoặc đóng khỏi stack, ngược lại đây là xâu ngoặc không cân bằng
// do đã vi phạm một vị trí → in NO luôn.
//------------------------------------------------------------------------------------------------//

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

char input[100];

struct Linkerlist
{
    char data;
    struct Linkerlist  *next;
};

typedef struct Linkerlist *node;

// Khoi tao mot node moi va gan gia tri cho no
//------------------------------------------------------------------------------------------------//
node newNode(char value)
{
    node temp;// bien temp theo kieu node
    temp = (node)malloc(sizeof(struct Linkerlist));// cap phat vung nho dung malloc()
    temp->next = NULL;// ch next tro toi null
    temp->data = value;// gan gia tri cho node
    return temp;// tra ve gia tri da duoc gan
}

// them mot node vao dau danh sach
//------------------------------------------------------------------------------------------------//
node Push(node head, char value)
{
    node temp,p = head;// bien temp theo kieu node
    temp = newNode(value);// khoi tao temp voi data = value
    if(head == NULL)
    {
        head = temp;// neu node dang trong thi node se = head
    }
    else
    {
       while(p->next != NULL)
       {
        p = p->next;
       }
        p->next = temp;
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
    if(head->next == NULL)
    {
        head = NULL;
    }
    else 
    {
        node p = head;
        while(p->next->next != NULL)
        {
            p = p->next;
        }
        p->next = NULL;
    }
    return head;// tra ve gia tri da duoc gan
}

// Ham lay gia tri cua mot nut bat ki
//------------------------------------------------------------------------------------------------//
int peekstack(node head)
{
    node p = head;
    while(p->next != NULL)
    {
    p = p->next;
    }
    return p->data;
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

// Hàm kiểm tra xem chuỗi s có thứ ngoặc đúng không
//------------------------------------------------------------------------------------------------//
int Parser(char s[])
{
    int n = strlen(s); // gán n là chiều dài chuỗi s
    node stack = initstack(); // khởi tạo stack
    for(int i = 0; i < n; i++) // duyệt từ đầu chuỗi đến cuối chuỗi
    {
        switch (s[i])
        {
            case '(':
            case '{':
            case '[':
                stack = Push(stack, s[i]); // nếu chuỗi là các kí tự (,{,[ thì thêm vào stack
                break;
            case ')':
                if(peekstack(stack) == '(') // nếu stack được so sanh là đúng
                    stack = Pop(stack); // thì lấy stack đó ra
                else
                    return 0; // ngược lại trả về 0;
                break; // và dừng lại
            case '}':
                if(peekstack(stack) == '{')
                    stack = Pop(stack);
                else
                    return 0;
                break;
            case ']':
                if(peekstack(stack) == '[')
                    stack = Pop(stack);
                else
                    return 0;
                break;
        }
    }
    if(isEmptystack(stack))
        return 1;
    else 
        return 0;
}

//in danh sách liên kết
void getStack(node head){
    if (head == NULL){
        return;
    }
    for (node p = head; p != NULL; p = p->next){
        printf("%2c", p->data);
    }
}

// Đọc dữ liệu từ file
//------------------------------------------------------------------------------------------------//
void readfile(char s[])
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
    while(fgets(s,100,Fin) != NULL)
    cout << s;
    s[strlen(s) - 1] = '\0';
    fclose(Fin);
}

// Chương trình chính
//------------------------------------------------------------------------------------------------//

int main()
{
    char s[100];
    cout <<"\t\t\t|-------------------------------------------------------------------------|"<<endl;
    cout <<"\t\t\t|                 STACK de kiem tra cu phap co dung hay khong             |"<<endl;
    cout <<"\t\t\t|                         CODE BY: NHAN CODER                             |"<<endl;
    cout <<"\t\t\t|-------------------------------------------------------------------------|"<<endl;
    readfile(s);
    Parser(s);
    if(Parser(s) == 1)
    {
        cout << "\tChuoi dung !";
    }
    else
    {
         cout << "\tChuoi sai !";
    }
    return 0;
}
