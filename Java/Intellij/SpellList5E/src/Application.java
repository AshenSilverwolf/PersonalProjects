import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.io.File;
import java.io.FileWriter;

public class Application {
    public static void main(String[] args) throws IOException {
        File archive = new File("/home/gavin/csp/PersonalProjects/Java/Intellij/SpellList5E/src/archive.txt");
        Scanner scnr = new Scanner(archive);
        FileWriter writer = new FileWriter(archive);
        Spell test = new Spell("Power Word Kill",
                "Enchantment",
                9, 6, 60,
                new ArrayList<String>(Arrays.asList("V")),
                false, false, "Instantaneous",
                new ArrayList<String>(Arrays.asList("Bard", "Sorcerer", "Warlock", "Wizard")),
                "You utter a word of power that can compel one creature you can see within range to die instantly. If the creature you choose has 100 hit points or fewer, it dies. Otherwise, the spell has no effect.",
                "N/A");
        Spell test2 = new Spell("Fireball", "Evocation", 3, 6, 150,
                new ArrayList<String>(Arrays.asList("V", "S", "M", "a tiny ball of bat guano and sulfur")),
                false, false, "Instantaneous",
                new ArrayList<String>(Arrays.asList("Cleric (Light)", "Sorcerer", "Warlock (Fiend)", "Wizard", "Fighter (Eldritch Knight)", "Rogue (Arcane Trickster)")),
                "A bright streak flashes from your pointing finger to a point you choose within range then blossoms with a low roar into an explosion of flame. Each creature in a 20-foot radius must make a Dexterity saving throw. A target takes 8d6 fire damage on a failed save, or half as much damage on a successful one. The fire spreads around corners. It ignites flammable objects in the area that aren't being worn or carried.",
                "When you cast this spell using a spell slot of 4th level or higher, the damage increases by 1d6 for each slot level above 3rd.");
        test.archiveSpell(writer);
        test2.archiveSpell(writer);
        writer.close();

        while (scnr.hasNextLine()) {
            System.out.println(scnr.nextLine());
        }
    }
}
