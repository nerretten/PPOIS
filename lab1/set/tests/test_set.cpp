#include <UnitTest++.h>
#include "../src/set.h"
#include <sstream>
#include <stdexcept>


TEST(DefaultConstructorCreatesEmptySet) {
    Set s;
    CHECK(s.is_empty());
    CHECK_EQUAL(0, s.power());
}

TEST(ConstructorFromEmptyStringThrows) {
            CHECK_THROW(Set(""), std::invalid_argument);
}

TEST(ConstructorFromMalformedStringThrows1) {
            CHECK_THROW(Set("{a, b"), std::invalid_argument);
}

TEST(ConstructorFromMalformedStringThrows2) {
            CHECK_THROW(Set("{a}}"), std::invalid_argument);
}

TEST(EmptySetFromString) {
    Set s("{}");
            CHECK(s.is_empty());
            CHECK_EQUAL(0, s.power());
}


TEST(SingleElementSet) {
    Set s("{a}");
    CHECK(!s.is_empty());
    CHECK_EQUAL(1, s.power());
    CHECK(s["a"]);
    CHECK(!s["b"]);
}

TEST(MultipleAtoms) {
    Set s("{x, y, z}");
            CHECK_EQUAL(3, s.power());
            CHECK(s["x"]);
            CHECK(s["y"]);
            CHECK(s["z"]);
            CHECK(!s["w"]);
}

TEST(SetWithSpaces) {
    Set s("{ a , b }");
            CHECK_EQUAL(2, s.power());
            CHECK(s["a"]);
            CHECK(s["b"]);
}

TEST(SetWithEmptySubset) {
    Set s("{ {} }");
            CHECK(!s.is_empty());
            CHECK_EQUAL(1, s.power());
    Set empty;
            CHECK(s[empty]);
}

TEST(SetWithNonEmptySubset) {
    Set s("{ {a} }");
            CHECK_EQUAL(1, s.power());
    Set inner("{a}");
            CHECK(s[inner]);
}

TEST(MixedSet) {
    Set s("{a, {b}}");
            CHECK_EQUAL(2, s.power());
            CHECK(s["a"]);
    Set inner("{b}");
            CHECK(s[inner]);
}

TEST(AddAtom) {
    Set s;
    s.add_element("x");
            CHECK_EQUAL(1, s.power());
            CHECK(s["x"]);
}

TEST(AddSubset) {
    Set s;
    Set inner("{y}");
    s.add_element(inner);
            CHECK_EQUAL(1, s.power());
            CHECK(s[inner]);
}

TEST(AddDuplicateAtomIgnored) {
    Set s;
    s.add_element("x");
    s.add_element("x");
            CHECK_EQUAL(1, s.power());
}

TEST(DeleteExistingAtom) {
    Set s("{x}");
    s.delete_element("x");
            CHECK(s.is_empty());
}

TEST(DeleteNonExistingAtom) {
    Set s("{x}");
    s.delete_element("y");
            CHECK_EQUAL(1, s.power());
            CHECK(s["x"]);
}

TEST(DeleteSubset) {
    Set inner("{a}");
    Set s;
    s.add_element(inner);
    s.delete_element(inner);
            CHECK(s.is_empty());
}

TEST(EmptySetsAreEqual) {
    Set s1, s2;
            CHECK(s1 == s2);
}

TEST(EqualSetsWithAtoms) {
    Set s1("{a, b}");
    Set s2("{b, a}");
            CHECK(s1 == s2);
}

TEST(NotEqualSets) {
    Set s1("{a}");
    Set s2("{b}");
            CHECK(s1 != s2);
}

TEST(UnionOfEmptySets) {
    Set s1, s2;
    Set result = s1 + s2;
            CHECK(result.is_empty());
}

TEST(UnionWithOverlap) {
    Set s1("{a, b}");
    Set s2("{b, c}");
    Set result = s1 + s2;
            CHECK_EQUAL(3, result.power());
            CHECK(result["a"]);
            CHECK(result["b"]);
            CHECK(result["c"]);
}

TEST(UnionAssignment) {
    Set s1("{a}");
    Set s2("{b}");
    s1 += s2;
            CHECK_EQUAL(2, s1.power());
            CHECK(s1["a"]);
            CHECK(s1["b"]);
}

TEST(IntersectionOfEmptySets) {
    Set s1, s2;
    Set result = s1 * s2;
            CHECK(result.is_empty());
}

TEST(IntersectionWithCommonElement) {
    Set s1("{a, b}");
    Set s2("{b, c}");
    Set result = s1 * s2;
            CHECK_EQUAL(1, result.power());
            CHECK(result["b"]);
}

TEST(Intersection){
    Set s1("{a, b, c}");
    Set s2("{a, {b}}");
    s1*=s2;
    Set result("{a}");
    CHECK(result==s1);
}

TEST(SetDifference) {
    Set s1("{a, b, c, {e,f}}");
    Set s2("{b, d, {e,f}}");
    Set result = s1 - s2;
            CHECK_EQUAL(2, result.power());
            CHECK(result["a"]);
            CHECK(result["c"]);
            CHECK(!result["b"]);
}

TEST(DifferenceAssignment) {
    Set s1("{a, b}");
    Set s2("{b}");
    s1 -= s2;
            CHECK_EQUAL(1, s1.power());
            CHECK(s1["a"]);
}

TEST(PowerSetOfEmptySet) {
    Set s;
    Set ps = s.boolean();
    CHECK_EQUAL(1, ps.power());
    Set empty;
            CHECK(ps[empty]);
}

TEST(PowerSetOfSingleton) {
    Set s("{a}");
    Set ps = s.boolean();
            CHECK_EQUAL(2, ps.power());
    Set empty;
    Set singleton("{a}");
            CHECK(ps[empty]);
            CHECK(ps[singleton]);
}

TEST(PowerSetOfComplexSet){
    Set s{"{a, {b, c}, {c,{d,e}}}"};
    Set ps = s.boolean();
    CHECK_EQUAL(8, ps.power());
    CHECK(ps[Set()]);
    CHECK(ps[Set("{a}")]);
    CHECK(ps[Set("{{b, c}}")]);
    CHECK(ps[Set("{{c,{d,e}}}")]);

    CHECK(ps[Set("{a, {b, c}}")]);
    CHECK(ps[Set("{a, {c,{d,e}}}")]);
    CHECK(ps[Set("{{b,c}, {c,{d,e}}}")]);

    CHECK(ps[Set("{{b,c}, {c,{d,e}}, a}")]);
}

TEST(ConstructorFromCString) {
    Set s("{hello}");
            CHECK_EQUAL(1, s.power());
            CHECK(s["hello"]);
}

TEST(OutputEmptySet) {
    Set s;
    std::ostringstream oss;
    oss << s;
            CHECK_EQUAL("{}", oss.str());
}


TEST(InputValidSet) {
    std::istringstream iss("{a, b}");
    Set s;
    iss >> s;
            CHECK_EQUAL(2, s.power());
            CHECK(s["a"]);
            CHECK(s["b"]);
}

TEST(InputInvalidSet) {
    std::istringstream iss("{a, b");
    Set s;
    iss >> s;
            CHECK(iss.fail());
}

TEST(EqualSetsWithSubsets) {
    Set s1("{ {a}, b }");
    Set s2("{ b, {a} }");
            CHECK(s1 == s2);
}

TEST(PowerWithSubsets) {
    Set s("{a, {b}, {c, d}}");
            CHECK_EQUAL(3, s.power());
}

TEST(MembershipOfSubset) {
    Set inner("{x, y}");
    Set s;
    s.add_element(inner);
            CHECK(s[inner]);
    Set other("{z}");
            CHECK(!s[other]);
}

TEST(UnionWithSubsets) {
    Set s1("{ {a} }");
    Set s2("{ {b} }");
    Set result = s1 + s2;
            CHECK_EQUAL(2, result.power());
            CHECK(result[Set("{a}")]);
            CHECK(result[Set("{b}")]);
}


int main() {
    return UnitTest::RunAllTests();
}

