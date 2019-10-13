import org.junit.jupiter.api.Test;

import java.util.Arrays;

import java.util.ArrayList;

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
        assertEquals(new ArrayList<String>(Arrays.asList("V", "S", "M")), test.getComponents());
    }

    @Test
    void isConcentration() {
        Spell test = new Spell();
        assertEquals(false, test.isConcentration());
    }

    @Test
    void isRitual() {
        Spell test = new Spell();
        assertEquals(false, test.isRitual());
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
        test.setConcentration(true);
        assertEquals(true, test.isConcentration());
    }

    @Test
    void setRitual() {
        Spell test = new Spell();
        test.setRitual(true);
        assertEquals(true, test.isRitual());
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
}