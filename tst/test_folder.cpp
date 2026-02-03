#include <gtest/gtest.h>
#include "folder.h"

TEST(FolderTest, AddAndRemoveNote) {
    Folder folder("TestFolder");

    int id = folder.addNote("A", "B");
    EXPECT_EQ(folder.all().size(), 1);

    EXPECT_TRUE(folder.removeNote(id));
    EXPECT_EQ(folder.all().size(), 0);
}

TEST(FolderTest, SearchWorks) {
    Folder folder("TestFolder");

    folder.addNote("Shopping", "Buy milk");
    folder.addNote("Work", "Send email");

    auto res = folder.search("milk");
    EXPECT_EQ(res.size(), 1);
}
//
// Created by corti on 03/02/2026.
//