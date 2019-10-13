import java.util.Scanner;
import java.lang.Character;

public class ConvertToPostfix {
    public static void main(String[] args) {
        Stack stack = new Stack();
        Scanner in = new Scanner(System.in);

        System.out.println("Please input an infix expression: ");
        String infix = in.next();
        String postfix = convertInfixToPostfix(infix, stack);

        System.out.println(postfix);
    }

    public static String convertInfixToPostfix(String infix, Stack stack) {
        String postfix = new String();

        for (int i = 0; i < infix.length(); i++) {
            if (Character.isDigit(infix.charAt(i))) {
                postfix += infix.charAt(i);
            } else if (isOperand(infix.charAt(i))) {
                while (!stack.stackIsEmpty() && getPriority(infix.charAt(i)) <= getPriority(stack.peek())) {
                    postfix += stack.pop();
                }
                stack.push(infix.charAt(i));
            } else if (infix.charAt(i) == '(') {
                stack.push(infix.charAt(i));
            } else if (infix.charAt(i) == ')') {
                postfix = parenthesisPop(stack, postfix);
            }
        }

        postfix = popUntilEmpty(stack, postfix);

        return postfix;
    }

    public static boolean isOperand(char x) {
        switch (x) {
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
                return true;
            default:
                return false;
        }
    }

    public static int getPriority(char x) {
        if (x == '+' || x == '-') {
            return 1;
        } else if (x == '*' || x == '/' || x == '%') {
            return 2;
        } else if (x == '^') {
            return 3;
        } else {
            return -1;
        }
    }

    public static String parenthesisPop(Stack stack, String postfix) {
        while (stack.peek() != '(') {
            postfix += stack.pop();
        }
        stack.pop();

        return postfix;
    }

    public static String popUntilEmpty(Stack stack, String postfix) {
        while (!stack.stackIsEmpty()) {
            postfix += stack.pop();
        }

        return postfix;
    }
}
