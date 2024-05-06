import java.util.Scanner;

public class Diem {
    private int x, y;

    public Diem() {
        x = 0;
        y = 0;
    }

    public Diem(int a, int b) {
        x = a;
        y = b;
    }

    public void nhap() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Nhập vào x: ");
        x = sc.nextInt();
        System.out.print("Nhập vào y: ");
        y = sc.nextInt();
    }

    public void in() {
        System.err.println("(" + x + ", " + y + ")");
    }

    public static void main(String[] args) {
        Diem a = new Diem();
        a.in();
        a.nhap();
        a.in();
    }
}