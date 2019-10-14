import java.io.IOException;
import java.util.Scanner;
import java.io.File;
import java.io.FileWriter;

public class Application {
    public static void main(String[] args) throws IOException {
        File archive = new File("/home/gavin/csp/PersonalProjects/Java/Intellij/SpellList5E/src/archive.txt");
        Scanner scnr = new Scanner(archive);
        FileWriter writer = new FileWriter(archive);
        Spell test = new Spell();
        test.archiveSpell(writer);
        writer.close();

        while (scnr.hasNextLine()) {
            System.out.println(scnr.nextLine());
        }
    }
}
