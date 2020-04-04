import org.junit.jupiter.api.Test;

import java.io.File;
import java.io.IOException;
import java.util.Arrays;
import java.util.ArrayList;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;

import static org.junit.jupiter.api.Assertions.*;

class SpellTest {

    @Test
    void getName() {
        Spell test = new Spell();
        assertEquals("defaultName", test.getName());
    }

    @Test
    void getSchool() {
        Spell test = new Spell();
        assertEquals("defaultSchool", test.getSchool());
    }

    @Test
    void getLevel() {
        Spell test = new Spell();
        assertEquals(0, test.getLevel());
    }

    @Test
    void getCastingTime() {
        Spell test = new Spell();
        assertEquals(0, test.getCastingTime());
    }

    @Test
    void getRange() {
        Spell test = new Spell();
        assertEquals(0, test.getRange());
    }

    @Test
    void getComponents() {
        Spell test = new Spell();
        assertEquals(new ArrayList<String>(Arrays.asList("V", "S", "M", "a white feather")), test.getComponents());
    }

    @Test
    void isConcentration() {
        Spell test = new Spell();
        assertEquals(true, test.isConcentration());
    }

    @Test
    void isRitual() {
        Spell test = new Spell();
        assertEquals(true, test.isRitual());
    }

    @Test
    void getDuration() {
        Spell test = new Spell();
        assertEquals("defaultDuration", test.getDuration());
    }

    @Test
    void getDescription() {
        Spell test = new Spell();
        assertEquals("defaultDescription", test.getDescription());
    }

    @Test
    void setName() {
        Spell test = new Spell();
        test.setName("Fireball");
        assertEquals("Fireball", test.getName());
    }

    @Test
    void setSchool() {
        Spell test = new Spell();
        test.setSchool("Abjuration");
        assertEquals("Abjuration", test.getSchool());
    }

    @Test
    void setLevel() {
        Spell test = new Spell();
        test.setLevel(3);
        assertEquals(3, test.getLevel());
    }

    @Test
    void setCastingTime() {
        Spell test = new Spell();
        test.setCastingTime(6);
        assertEquals(6, test.getCastingTime());
    }

    @Test
    void setRange() {
        Spell test = new Spell();
        test.setRange(30);
        assertEquals(30, test.getRange());
    }

    @Test
    void setComponents() {
        Spell test = new Spell();
        test.setComponents(new ArrayList<String>(Arrays.asList("V", "S", "M", "a red dragon's scale")));
        assertEquals(new ArrayList<String>(Arrays.asList("V", "S", "M", "a red dragon's scale")), test.getComponents());
    }

    @Test
    void setConcentration() {
        Spell test = new Spell();
        test.setConcentration(false);
        assertEquals(false, test.isConcentration());
    }

    @Test
    void setRitual() {
        Spell test = new Spell();
        test.setRitual(false);
        assertEquals(false, test.isRitual());
    }

    @Test
    void setDuration() {
        Spell test = new Spell();
        test.setDuration("10 minutes");
        assertEquals("10 minutes", test.getDuration());
    }

    @Test
    void setDescription() {
        Spell test = new Spell();
        test.setDescription("You touch one object that is no larger than 10 feet in any dimension. Until the spell ends, the object sheds bright light in a 20-foot radius and dim light for an additional 20 feet. The ligght can be colored as you like. Completely covering the object with something opaque blocks the light. The spell ends if you cast it again or dismiss it as an action.\n\nIf you target an object held or worn by a hostile creature, that creature must succeed on a Dexterity saving throw to avoid the spell.");
        assertEquals("You touch one object that is no larger than 10 feet in any dimension. Until the spell ends, the object sheds bright light in a 20-foot radius and dim light for an additional 20 feet. The ligght can be colored as you like. Completely covering the object with something opaque blocks the light. The spell ends if you cast it again or dismiss it as an action.\n\nIf you target an object held or worn by a hostile creature, that creature must succeed on a Dexterity saving throw to avoid the spell.", test.getDescription());
    }

    @Test
    void testArchiveSpell() throws IOException {
        File archive = new File("archive.txt");
        FileWriter out = new FileWriter(archive);
        Scanner scnr = new Scanner(archive);
        Spell test = new Spell();
        test.archiveSpell(out);
        out.close();

        assertEquals(test.getName(), scnr.nextLine());

        assertEquals(test.getSchool(), scnr.nextLine());

        scnr.next();

        assertEquals(test.getLevel(), scnr.nextInt());

        scnr.next();
        scnr.next();

        assertEquals(test.getCastingTime(), scnr.nextInt());

        scnr.next();

        assertEquals(test.getRange(), scnr.nextInt());

        scnr.nextLine();

        ArrayList<String> testArrayList = new ArrayList<>();
        String componentLine = scnr.nextLine();
        int j = 0;
        boolean newStringFlag = false;
        boolean firstChar = true;
        boolean materials = false;
        // for loop to convert the line of components into a valid ArrayList called testArrayList
        for (int i = 0; i < componentLine.length(); i++) {
            if (materials) {
                if (firstChar) {
                    testArrayList.add(j, "" + componentLine.charAt(i));
                    firstChar = false;
                } else {
                    if (!(componentLine.charAt(i) == ')')) {
                        testArrayList.set(j, testArrayList.get(j) + componentLine.charAt(i));
                    } else {
                        continue;
                    }
                }
            } else {
                if (firstChar) {
                    testArrayList.add(j, "" + componentLine.charAt(i));
                    firstChar = false;
                    if (componentLine.charAt(i) == 'M') {
                        materials = true;
                        firstChar = true;
                        i += 2;
                        j++;
                    }
                } else {
                    if (!newStringFlag && componentLine.charAt(i) == ',') {
                        newStringFlag = true;
                        j++;
                        continue;
                    } else if (newStringFlag && componentLine.charAt(i) == ' ') {
                        newStringFlag = false;
                        firstChar = true;
                    }
                }
            }
        }
        assertEquals(test.getComponents(), testArrayList);

        if (scnr.next().compareTo("Ritual") == 0) {
            assertEquals(true, test.isRitual());
            scnr.next();
        } else {
            assertEquals(false, test.isRitual());
        }

        String durationLine = scnr.nextLine();
        if (durationLine.charAt(1) == 'C') {
            assertEquals(true, test.isConcentration());
            durationLine = durationLine.substring(15);
        }
        durationLine = durationLine.substring(1);
        assertEquals(test.getDuration(), durationLine);

        j = 0;
        firstChar = true;
        ArrayList<String> classArrayList = new ArrayList<>();
        String classLine = scnr.nextLine();
        classLine = classLine.substring(9);
        for (int i = 0; i < classLine.length(); i++) {
            if (firstChar) {
                classArrayList.add(j, "" + classLine.charAt(i));
                firstChar = false;
            } else {
                if (classLine.charAt(i) == ',') {
                    j++;
                    i++;
                    firstChar = true;
                    continue;
                } else {
                    classArrayList.set(j, classArrayList.get(j) + classLine.charAt(i));
                }
            }
        }
        assertEquals(test.getClasses(), classArrayList);

        assertEquals(test.getDescription(), scnr.nextLine());
        assertEquals(test.getHigherLevel(), scnr.nextLine().substring(18));
    }
}