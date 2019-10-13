import java.util.ArrayList;

public class Stack {
    private ArrayList<Character> stack = new ArrayList<>();
    private int top;

    public Stack() {
        this.top = -1;
    }

    public void push(char element) {
        stack.add(element);
        top++;
    }

    public char pop() {
        char popper = stack.get(top);
        stack.remove(top--);
        return popper;
    }

    public char peek() {
        return stack.get(top);
    }

    public boolean stackIsEmpty() {
        if (stack.isEmpty()) {
            return true;
        } else {
            return false;
        }
    }
}
