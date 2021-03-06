#pragma once

#include "lang/ast_node.hpp"

#include "views/view.hpp"
#include "lang/pattern_data.hpp"

#include "providers/provider.hpp"

#include <cstring>
#include <filesystem>
#include <thread>

#include "ImGuiFileBrowser.h"
#include "TextEditor.h"

namespace hex {

    class ViewPattern : public View {
    public:
        explicit ViewPattern(std::vector<lang::PatternData*> &patternData);
        ~ViewPattern() override;

        void drawMenu() override;
        void drawContent() override;

    private:
        std::vector<lang::PatternData*> &m_patternData;
        std::filesystem::path m_possiblePatternFile;

        TextEditor m_textEditor;
        imgui_addons::ImGuiFileBrowser m_fileBrowser;

        void loadPatternFile(std::string path);
        void clearPatternData();
        void parsePattern(char *buffer);
    };

}