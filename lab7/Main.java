import java.util.Random;
import java.util.Scanner;

// import java.io.*;

/*
concat (объединяет строки, может объединять две и
более строк), 
concat_ws (объединяет строки, но в качестве первого параметра
принимает разделитель, который будет соединять строки), 
length (возвращает
количество символов в строке), 
ltrim (удаляет начальные пробелы в строке),
rtrim (удаляет конечные пробелы в строке). 
Использовать конструктор с
параметрами, конструктор без параметров, конструктор копирования. В
класс добавить необходимый набор полей и методов (минимум два поля и
два метода) на свое усмотрение. Создать методы доступа к полям класса.
*/


public class Main{
    public static void main(String[] args) {

        // 1 TASK
        System.out.print("1) Enter your name: ");
        Scanner scan = new Scanner(System.in);
        String name = scan.next();

        System.out.println("Hi, " + name + "\n");

        // 2 TASK
        int len = args.length;
        
        System.out.println("2) Print args in reverse order (in a column): ");
        for (int i = 1; i < len + 1; i++){
            System.out.print(args[len - i] + " ");
        }

        // 3 TASK
        Random rand = new Random();

        System.out.print("3) How many digits to print: ");
        int count = scan.nextInt();
        for (int i = 0; i < count; i++){
            int num = rand.nextInt(23);
            System.out.print(num + ", ");
        }

        
        String[] strs = new String[] {"hello", "world"};

        System.out.println("\n" + CustomString.concat(strs));
        System.out.println("\n" + CustomString.concat_ws(strs, ":"));

    }
}