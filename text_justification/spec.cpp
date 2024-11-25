#include <bits/stdc++.h>
#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
    vector<string> words;
    int maxWidth;
    vector<string> result;

    void InputFormat() {
        LINES(words) % SIZE(1, 300);
        LINE(maxWidth);
    }

    void OutputFormat() {
        LINES(result);
    }

    void Constraints() {
        CONS(1 <= words.size() && words.size() <= 300);
        CONS(allElementsLengthBetween(words, 1, 20));
        CONS(1 <= maxWidth && maxWidth <= 100);
        CONS(allWordsFitWidth(words, maxWidth));
    }

private:
    bool allElementsLengthBetween(const vector<string>& v, int lo, int hi) {
        for (const string& word : v) {
            if (word.length() < lo || word.length() > hi) {
                return false;
            }
        }
        return true;
    }

    bool allWordsFitWidth(const vector<string>& v, int maxWidth) {
        for (const string& word : v) {
            if (word.length() > maxWidth) {
                return false;
            }
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "This is an example of text justification.",
            "16"
        });
        Output({
            "This    is    an",
            "example  of text",
            "justification.  "
        });
    }

    void SampleTestCase2() {
        Input({
            "What must be acknowledgment shall be",
            "16"
        });
        Output({
            "What   must   be",
            "acknowledgment  ",
            "shall be        "
        });
    }

    void SampleTestCase3() {
        Input({
            "Science is what we understand well enough to explain to a computer. Art is everything else we do",
            "20"
        });
        Output({
            "Science  is  what we",
            "understand      well",
            "enough to explain to",
            "a  computer.  Art is",
            "everything  else  we",
            "do                  "
        });
    }

    void BeforeTestCase() {
        words.clear();
        result.clear();
    }

    void TestGroup1() {
        CASE(words = {"a"}, maxWidth = 1);
        CASE(words = {"word", "word"}, maxWidth = 5);
        CASE(words = {"word"}, maxWidth = 10);
        CASE(words = {"single", "word", "line"}, maxWidth = 15);

        for (int i = 0; i < 5; i++) {
            CASE(words = randomWords(10, 20, 5), maxWidth = rnd.nextInt(10, 30));
        }
    }

    void TestGroup2() {
        CASE(words = vector<string>(300, "a"), maxWidth = 300);
        CASE(words = vector<string>(100, "abc"), maxWidth = 50);

        for (int i = 0; i < 5; i++) {
            CASE(words = randomWords(300, 1, 20), maxWidth = rnd.nextInt(1, 100));
        }
    }

    void TestGroup3() {
        CASE(words = {"a", "b", "c", "d"}, maxWidth = 1);
        CASE(words = {"example", "for", "a", "single", "line"}, maxWidth = 25);
        CASE(words = {"lorem", "ipsum", "dolor", "sit", "amet"}, maxWidth = 50);

        for (int i = 0; i < 5; i++) {
            CASE(words = randomWords(50, 1, 20), maxWidth = rnd.nextInt(10, 50));
        }
    }

private:
    vector<string> randomWords(int count, int minLength, int maxLength) {
        vector<string> result;
        for (int i = 0; i < count; i++) {
            int len = rnd.nextInt(minLength, maxLength);
            string word(len, 'a');
            for (int j = 0; j < len; j++) {
                word[j] = 'a' + rnd.nextInt(0, 25);
            }
            result.push_back(word);
        }
        return result;
    }
};
