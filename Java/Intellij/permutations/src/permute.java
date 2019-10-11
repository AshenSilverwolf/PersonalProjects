import java.util.Scanner;

public class permute {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String thing = new String();
        System.out.println("Please input a string:");
        thing = in.next();

        permuteString(thing, "");
    }

    static void permuteString(String s, String t) {
        if (s.length() == 0) {
            System.out.println(t);
            return;
        }

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            permuteString(s.substring(0, i) + s.substring(i + 1), t + c);
        }
    }
}
