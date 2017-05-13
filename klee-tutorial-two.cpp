#include "gtest/gtest.h"

/*
 * Simple regular expression matching.
 *
 * From:
 *   The Practice of Programming
 *   Brian W. Kernighan, Rob Pike
 *
 */

static int matchhere(char*,char*);

static int matchstar(int c, char *re, char *text) {
  do {
    if (matchhere(re, text))
      return 1;
  } while (*text != '\0' && (*text++ == c || c== '.'));
  return 0;
}

static int matchhere(char *re, char *text) {
  if (re[0] == '\0')
    return 0;
  if (re[1] == '*')
    return matchstar(re[0], re+2, text);
  if (re[0] == '$' && re[1]=='\0')
    return *text == '\0';
  if (*text != '\0' && (re[0]=='.' || re[0]==*text))
    return matchhere(re+1, text+1);
  return 0;
}

int match(char *re, char *text) {
  if (re[0] == '^')
    return matchhere(re+1, text);
  do {
    if (matchhere(re, text))
      return 1;
  } while (*text++ != '\0');
  return 0;
}

TEST(KleeTest, kill_Mutation1) {
  char re[] = "^1*$";

  int res = match(re, (char *)"11");

  ASSERT_EQ(res, 1);
}
TEST(KleeTest, killMutation2) {
  char re[] = "^h$";

  int res = match(re, (char *)"h");

  ASSERT_EQ(res, 1);
}

//TEST(KleeTest, killFirstTwoOfFourMutations) {
//  char re[] = "^.$";
//
//  int res = match(re, (char *)"h");
//
//  ASSERT_EQ(res, 1);
//}

#pragma mark - Tests: "hello" group

TEST(KleeTest, hello_test000001) {
  char re[] = "^";

  int res = match(re, (char *)"hello");

  ASSERT_EQ(res, 0);
}

TEST(KleeTest, hello_test000002) {
  char re[] = "^$";

  int res = match(re, (char *)"hello");

  ASSERT_EQ(res, 0);
}

TEST(KleeTest, hello_test000003) {
  char re[] = "^$\x01";

  int res = match(re, (char *)"hello");

  ASSERT_EQ(res, 0);
}

TEST(KleeTest, hello_test000004) {
  char re[] = "^\x01";

  int res = match(re, (char *)"hello");

  ASSERT_EQ(res, 0);
}

TEST(KleeTest, hello_test000005) {
  char re[] = "^.";

  int res = match(re, (char *)"hello");

  ASSERT_EQ(res, 0);
}

TEST(KleeTest, hello_test000006) {
  char re[] = "^\x01*";

  int res = match(re, (char *)"hello");

  ASSERT_EQ(res, 0);
}

TEST(KleeTest, hello_test000007) {
  char re[] = "^h";

  int res = match(re, (char *)"hello");

  ASSERT_EQ(res, 0);
}

TEST(KleeTest, hello_test000008) {
  char re[] = "";

  int res = match(re, (char *)"hello");

  ASSERT_EQ(res, 0);
}

TEST(KleeTest, hello_test000009) {
  char re[] = "^.*";

  int res = match(re, (char *)"hello");

  ASSERT_EQ(res, 0);
}

TEST(KleeTest, hello_test000010) {
  char re[] = "$";

  int res = match(re, (char *)"hello");

  ASSERT_EQ(res, 1);
}

TEST(KleeTest, hello_test000011) {
  char re[] = "$\x01";

  int res = match(re, (char *)"hello");

  ASSERT_EQ(res, 0);
}

TEST(KleeTest, hello_test000012) {
  char re[] = "^.*$";

  int res = match(re, (char *)"hello");

  ASSERT_EQ(res, 1);
}

TEST(KleeTest, hello_test000013) {
  char re[] = "e";

  int res = match(re, (char *)"hello");

  ASSERT_EQ(res, 0);
}

TEST(KleeTest, hello_test000014) {
  char re[] = ".*";

  int res = match(re, (char *)"hello");

  ASSERT_EQ(res, 0);
}
//
#pragma mark - Tests: "h" group

TEST(KleeTest, h_test000001) {
  char re[] = "^";

  int res = match(re, (char *)"h");

  ASSERT_EQ(res, 0);
}

TEST(KleeTest, h_test000002) {
  char re[] = "";

  int res = match(re, (char *)"h");

  ASSERT_EQ(res, 0);
}

TEST(KleeTest, h_test000003) {
  char re[] = "^$";

  int res = match(re, (char *)"h");

  ASSERT_EQ(res, 0);
}

TEST(KleeTest, h_test000004) {
  char re[] = "^\x01";

  int res = match(re, (char *)"h");

  ASSERT_EQ(res, 0);
}

TEST(KleeTest, h_test000005) {
  char re[] = "^$\x01";

  int res = match(re, (char *)"h");

  ASSERT_EQ(res, 0);
}

TEST(KleeTest, h_test000006) {
  char re[] = "^.";

  int res = match(re, (char *)"h");

  ASSERT_EQ(res, 0);
}

TEST(KleeTest, h_test000007) {
  char re[] = "^\x01*";

  int res = match(re, (char *)"h");

  ASSERT_EQ(res, 0);
}

TEST(KleeTest, h_test000008) {
  char re[] = "^h";

  int res = match(re, (char *)"h");

  ASSERT_EQ(res, 0);
}

TEST(KleeTest, h_test000009) {
  char re[] = "^.\x01";

  int res = match(re, (char *)"h");

  ASSERT_EQ(res, 0);
}

TEST(KleeTest, h_test000010) {
  char re[] = "^.*";

  int res = match(re, (char *)"h");

  ASSERT_EQ(res, 0);
}

TEST(KleeTest, h_test000011) {
  char re[] = "$";

  int res = match(re, (char *)"h");

  ASSERT_EQ(res, 1);
}

TEST(KleeTest, h_test000012) {
  char re[] = "^.\x01*$";

  int res = match(re, (char *)"h");

  ASSERT_EQ(res, 1);
}

TEST(KleeTest, h_test000013) {
  char re[] = ".*";

  int res = match(re, (char *)"h");

  ASSERT_EQ(res, 0);
}

#pragma mark - Tests: "" group

TEST(KleeTest, empty_test000001) {
  char re[] = "^";

  int res = match(re, (char *)"");

  ASSERT_EQ(res, 0);
}

TEST(KleeTest, empty_test000002) {
  char re[] = "";

  int res = match(re, (char *)"");

  ASSERT_EQ(res, 0);
}

TEST(KleeTest, empty_test000003) {
  char re[] = "^\x01";

  int res = match(re, (char *)"");

  ASSERT_EQ(res, 0);
}

TEST(KleeTest, empty_test000004) {
  char re[] = "\x01";

  int res = match(re, (char *)"");

  ASSERT_EQ(res, 0);
}

TEST(KleeTest, empty_test000005) {
  char re[] = "$";

  int res = match(re, (char *)"");

  ASSERT_EQ(res, 1);
}

TEST(KleeTest, empty_test000006) {
  char re[] = "$\x01";

  int res = match(re, (char *)"");

  ASSERT_EQ(res, 0);
}

TEST(KleeTest, empty_test000007) {
  char re[] = "^\x01*";

  int res = match(re, (char *)"");

  ASSERT_EQ(res, 0);
}

TEST(KleeTest, empty_test000008) {
  char re[] = "\x01*";

  int res = match(re, (char *)"");

  ASSERT_EQ(res, 0);
}

TEST(KleeTest, empty_test000009) {
  char re[] = "\x01*$";

  int res = match(re, (char *)"");

  ASSERT_EQ(res, 1);
}

//#pragma mark - Tests: "hhh" group
//
//TEST(KleeTest, hhh_test000001) {
//  char re[] = "^";
//
//  int res = match(re, (char *)"hhh");
//
//  ASSERT_EQ(res, 0);
//}
//
//TEST(KleeTest, hhh_test000002) {
//  char re[] = "^$";
//
//  int res = match(re, (char *)"hhh");
//
//  ASSERT_EQ(res, 0);
//}
//
//TEST(KleeTest, hhh_test000003) {
//  char re[] = "^\x01";
//
//  int res = match(re, (char *)"hhh");
//
//  ASSERT_EQ(res, 0);
//}
//
//TEST(KleeTest, hhh_test000004) {
//  char re[] = "^.";
//
//  int res = match(re, (char *)"hhh");
//
//  ASSERT_EQ(res, 0);
//}
//
//TEST(KleeTest, hhh_test000005) {
//  char re[] = "^h";
//
//  int res = match(re, (char *)"hhh");
//
//  ASSERT_EQ(res, 0);
//}
//
//TEST(KleeTest, hhh_test000006) {
//  char re[] = "";
//
//  int res = match(re, (char *)"hhh");
//
//  ASSERT_EQ(res, 0);
//}
//
//TEST(KleeTest, hhh_test000007) {
//  char re[] = "$";
//
//  int res = match(re, (char *)"hhh");
//
//  ASSERT_EQ(res, 1);
//}
//
//TEST(KleeTest, hhh_test000008) {
//  char re[] = "\x01*";
//
//  int res = match(re, (char *)"hhh");
//
//  ASSERT_EQ(res, 0);
//}
//
//TEST(KleeTest, hhh_test000009) {
//  char re[] = "$\x01";
//
//  int res = match(re, (char *)"hhh");
//
//  ASSERT_EQ(res, 0);
//}
//
//TEST(KleeTest, hhh_test000010) {
//  char re[] = ".*";
//
//  int res = match(re, (char *)"hhh");
//
//  ASSERT_EQ(res, 0);
//}
