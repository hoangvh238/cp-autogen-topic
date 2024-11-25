#include <tcframe/spec.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
    vector<string> words;
    int maxWidth;
    vector<string> res;

    void InputFormat() {
        LINE(words % SIZE(1, 300));
        LINE(maxWidth);
    }

    void OutputFormat() {
        LINES(res % SIZE(1, 100));
    }

    void Constraints() {
        CONS(1 <= words.size() && words.size() <= 300);
        CONS(1 <= maxWidth && maxWidth <= 100);
        CONS(validWords(words, maxWidth));
    }

    void Subtask1() {
        Points(100);
    }

private:
    bool validWords(const vector<string>& words, int maxWidth) {
        for (const string& word : words) {
            if (word.size() > maxWidth || word.empty()) {
                return false;
            }
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Subtasks({1});
        Input({
            "\"This\", \"is\", \"an\", \"example\", \"of\", \"text\", \"justification.\"",
            "16"
        });
        Output({
            "\"This    is    an\"",
            "\"example  of text\"",
            "\"justification.  \""
        });
    }

    void SampleTestCase2() {
        Subtasks({1});
        Input({
            "\"What\", \"must\", \"be\", \"acknowledgment\", \"shall\", \"be\"",
            "16"
        });
        Output({
            "\"What   must   be\"",
            "\"acknowledgment  \"",
            "\"shall be        \""
        });
    }

    void SampleTestCase3() {
        Subtasks({1});
        Input({
            "\"Science\", \"is\", \"what\", \"we\", \"understand\", \"well\", \"enough\", \"to\", \"explain\", \"to\", \"a\", \"computer.\", \"Art\", \"is\", \"everything\", \"else\", \"we\", \"do\"",
            "20"
        });
        Output({
            "\"Science  is  what we\"",
            "\"understand      well\"",
            "\"enough to explain to\"",
            "\"a  computer.  Art is\"",
            "\"everything  else  we\"",
            "\"do                  \""
        });
    }

    void BeforeTestCase() {
        words.clear();
        res.clear();
    }

    void TestGroup1() {
        Subtasks({1});
        CASE(words = {"This", "is", "a", "test"}, maxWidth = 10);
        CASE(words = {"This", "is", "another", "test", "case", "to", "verify"}, maxWidth = 20);
        CASE(words = {"word", "that", "fits"}, maxWidth = 15);
        CASE(words = generateRandomWords(10, 5, 50), maxWidth = 20);
        CASE(words = generateRandomWords(300, 1, 100), maxWidth = 100);
    }

    void TestGroup2() {
        Subtasks({1});
        CASE(words = {"short", "test", "line"}, maxWidth = 5);
        CASE(words = {"a", "single", "longword"}, maxWidth = 10);
        CASE(words = generateRandomWords(100, 5, 10), maxWidth = 8);
        CASE(words = generateRandomWords(50, 1, 20), maxWidth = 15);
        CASE(words = generateRandomWords(300, 1, 15), maxWidth = 15);
    }

private:
    vector<string> generateRandomWords(int n, int minLength, int maxLength) {
        vector<string> result;
        for (int i = 0; i < n; i++) {
            int len = rnd.nextInt(minLength, maxLength);
            string word(len, 'a');
            for (int j = 0; j < len; j++) {
                word[j] = rnd.nextInt('a', 'z');
            }
            result.push_back(word);
        }
        return result;
    }
};
