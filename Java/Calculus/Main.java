import vectors.Vector3D;

class Main {

    public static void main(String[] args) {

        Vector3D a = new Vector3D(5,3,-3);
        Vector3D b = new Vector3D(5,4,1);

        Vector3D c = Vector3D.crossProduct(a, b);
        c.printVector();
    }
}