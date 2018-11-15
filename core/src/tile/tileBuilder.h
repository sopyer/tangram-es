#pragma once

#include "data/tileSource.h"
#include "labels/labelCollider.h"
#include "scene/styleContext.h"
#include "scene/drawRule.h"

namespace Tangram {

class DataLayer;
class StyleBuilder;
class Tile;
class TileSource;
struct Feature;
struct Properties;
struct TileData;

class TileBuilder {

public:

    explicit TileBuilder(Scene& _scene);

    ~TileBuilder();

    StyleBuilder* getStyleBuilder(const std::string& _name);

    std::unique_ptr<Tile> build(TileID _tileID, const TileData& _data, const TileSource& _source);

    const Scene& scene() const { return m_scene; }

    // For testing
    TileBuilder(Scene& _scene, StyleContext* _styleContext);

private:

    // Determine and apply DrawRules for a @_feature
    void applyStyling(const Feature& _feature, const SceneLayer& _layer);

    Scene& m_scene;

    std::unique_ptr<StyleContext> m_styleContext;
    DrawRuleMergeSet m_ruleSet;

    LabelCollider m_labelLayout;

    fastmap<std::string, std::unique_ptr<StyleBuilder>> m_styleBuilder;

    fastmap<uint32_t, std::shared_ptr<Properties>> m_selectionFeatures;
};

}
