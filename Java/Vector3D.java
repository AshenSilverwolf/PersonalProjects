package vectors;
public class Vector3D {
    int x, y, z;

    public Vector3D() {

        this.x = 0;
        this.y = 0;
        this.z = 0;
    }

    public Vector3D(int x, int y, int z) {

        this.x = x;
        this.y = y;
        this.z = z;
    }

    public static int dotProduct(Vector3D a, Vector3D b) {

        return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
    }

    public static Vector3D crossProduct(Vector3D a, Vector3D b) {

        Vector3D c = new Vector3D();

        c.x = ((a.y * b.z) - (a.z * b.y));
        c.y = -((a.x * b.z) - (a.z * b.x));
        c.z = ((a.x * b.y) - (a.y * b.x));

        return c;
    }

    public static int TripleProduct(Vector3D a, Vector3D b, Vector3D c) {

        return dotProduct(a, crossProduct(b, c));
    }

    public void printVector() {

        System.out.printf("<%d,%d,%d>\n", this.x, this.y, this.z);
    }
}