#include <gtest/gtest.h>
#include "note.h"

TEST(NoteTest, CreationAndEdit) {
    Note n(1, "Title", "Text");

    EXPECT_EQ(n.id(), 1);
    EXPECT_EQ(n.title(), "Title");
    EXPECT_EQ(n.text(), "Text");

    EXPECT_TRUE(n.setTitle("New title"));
    EXPECT_EQ(n.title(), "New title");
}

TEST(NoteTest, LockPreventsEdit) {
    Note n(1, "Title", "Text");
    n.lock();

    EXPECT_FALSE(n.setText("Blocked"));
    EXPECT_EQ(n.text(), "Text");
}
//
// Created by corti on 03/02/2026.
//