#include "nbdatamnger.h"

NBDataMnger::NBDataMnger()
{
    import("DefShape.xml");
}

int NBDataMnger::createShape(QString id, b2Shape* s)
{
    if(shapes.contains(id)){
        return 1;
    }
    shapes[id] = s;
    return 0;
}

void NBDataMnger::load(string fileName)
{

}

void NBDataMnger::import(string fileName)
{
    qDebug()<<__FUNCTION__<<QString::fromStdString(fileName);
    tinyxml2::XMLDocument dom;
    dom.LoadFile(fileName.c_str());
    XMLNode *root = dom.RootElement();
    XMLNode *n = root->FirstChild();
    while(n){
        XMLElement *elm = n->ToElement();
        qDebug()<<elm->Name();
        if(string(elm->Name()) == "Shape"){
            createShape(elm);
        }
        n = n->NextSibling();
    }
}

void NBDataMnger::shapeExport(QString fileName, QString shapeID)
{

}

int NBDataMnger::createShape(XMLElement *elm)
{
    QString id(elm->Attribute("id"));
    int shapeType = elm->IntAttribute("shapeType");
    qDebug()<<__FUNCTION__<<id<<shapeType;
    if(shapeType == b2Shape::e_circle){
        b2CircleShape* shape = new b2CircleShape;
        XMLElement* centerElm = elm->FirstChildElement("center");
        shape->m_p.x = centerElm->FloatAttribute("x");
        shape->m_p.y = centerElm->FloatAttribute("y");
        shape->m_radius = elm->FirstChildElement("radius")->FloatAttribute("value");
        shapes[id] = shape;
        return 0;
    }

    if(shapeType == b2Shape::e_edge){
        b2EdgeShape* shape = new b2EdgeShape;
        XMLNode* n = elm->FirstChild();
        XMLElement* v1 = elm->FirstChildElement("v1");
        shape->m_vertex1.x = v1->FloatAttribute("x");
        shape->m_vertex1.y = v1->FloatAttribute("y");
        XMLElement* v2 = elm->FirstChildElement("v2");
        shape->m_vertex2.x = v2->FloatAttribute("x");
        shape->m_vertex2.y = v2->FloatAttribute("y");
        shapes[id] = shape;
        return 0;
    }

    if(shapeType == b2Shape::e_polygon){
        b2PolygonShape* shape = new b2PolygonShape;
        XMLNode* n = elm->FirstChild();
        QVector<b2Vec2> vecs;
        while(n){
            XMLElement* vecElm = n->ToElement();
            b2Vec2 vec(vecElm->FloatAttribute("x"),vecElm->FloatAttribute("y"));
            vecs.append(vec);
            n = n->NextSibling();
        }
        shape->Set(vecs.data(),vecs.size());
        shapes[id] = shape;
        return 0;
    }

    if(shapeType == b2Shape::e_chain){
        b2ChainShape* shape = new b2ChainShape;
        XMLNode* n = elm->FirstChild();
        QVector<b2Vec2> vecs;
        while(n){
            XMLElement* vecElm = n->ToElement();
            b2Vec2 vec(vecElm->FloatAttribute("x"),vecElm->FloatAttribute("y"));
            vecs.append(vec);
            n = n->NextSibling();
        }
        shape->CreateChain(vecs.data(),vecs.size());
        shapes[id] = shape;
        return 0;
    }
    return 1;
}

void NBDataMnger::save(QString fileName)
{
    tinyxml2::XMLDocument dom;
    XMLNode* root = dom.LinkEndChild(dom.NewElement("NBData"));
    foreach(QString shapeId,shapes.keys()){
        writeShape(&dom,root,shapeId.toStdString(),shapes[shapeId]);
    }
    dom.SaveFile(fileName.toStdString().c_str());
}

int NBDataMnger::delShape(QString id)
{
    if(shapes.contains(id)){
        delete shapes[id];
        shapes.erase(shapes.find(id));
        return 0;
    }
    return 1;
}

void NBDataMnger::writeShape(tinyxml2::XMLDocument *dom, XMLNode *parent, string id, b2Shape *shape)
{
    XMLElement* shapeNode = dom->NewElement("Shape");
    parent->LinkEndChild(shapeNode);
    shapeNode->SetAttribute("id",id.c_str());
    shapeNode->SetAttribute("shapeType",shape->m_type);
    ///
    ///write circle shape
    ///
    if(shape->m_type == b2Shape::e_circle){
        b2CircleShape *s = (b2CircleShape*)shape;
        XMLElement* center = dom->NewElement("center");
        center->SetAttribute("x",s->m_p.x);
        center->SetAttribute("y",s->m_p.y);
        shapeNode->LinkEndChild(center);
        XMLElement* radius = dom->NewElement("radius");
        radius->SetAttribute("value",s->m_radius);
        shapeNode->LinkEndChild(radius);
    }
    ///
    ///write edge shape
    ///
    if(shape->m_type == b2Shape::e_edge){
        b2EdgeShape *s = (b2EdgeShape*)shape;
        XMLElement* v1 = dom->NewElement("v1");
        shapeNode->LinkEndChild(v1);
        v1->SetAttribute("x",s->m_vertex1.x);
        v1->SetAttribute("y",s->m_vertex1.y);
        XMLElement* v2 = dom->NewElement("v2");
        shapeNode->LinkEndChild(v2);
        v2->SetAttribute("x",s->m_vertex2.x);
        v2->SetAttribute("y",s->m_vertex2.y);
    }
    ///
    ///write polygon shape
    ///
    if(shape->m_type == b2Shape::e_polygon){
        b2PolygonShape *s = (b2PolygonShape*)shape;
        for(int i = 0;i<s->GetVertexCount();i++){
            XMLElement* v1 = dom->NewElement("vertex");
            shapeNode->LinkEndChild(v1);
            b2Vec2 vertex = s->GetVertex(i);
            v1->SetAttribute("x",vertex.x);
            v1->SetAttribute("y",vertex.y);
        }
    }
    ///
    ///write chain shape
    ///
    if(shape->m_type == b2Shape::e_chain){
        b2ChainShape *s = (b2ChainShape*)shape;
        for(int i = 0;i<s->GetChildCount();i++){
            XMLElement* v1 = dom->NewElement("vertex");
            shapeNode->LinkEndChild(v1);
            b2EdgeShape edge;
            s->GetChildEdge(&edge,i);
            v1->SetAttribute("x",edge.m_vertex1.x);
            v1->SetAttribute("y",edge.m_vertex1.y);
        }
        XMLElement* v2 = dom->NewElement("vertex");
        shapeNode->LinkEndChild(v2);
        b2EdgeShape edge;
        s->GetChildEdge(&edge,s->GetChildCount()-1);
        v2->SetAttribute("x",edge.m_vertex2.x);
        v2->SetAttribute("y",edge.m_vertex2.y);
    }
}

b2Shape *NBDataMnger::readShape(XMLNode *node)
{
    b2Shape* shape = nullptr;
    XMLElement* elm = node->ToElement();
    int type = elm->IntAttribute("shapeType");

    if(type == b2Shape::e_circle){
        b2CircleShape* s  = new b2CircleShape;
        shape = s;
        s->m_p.x = elm->FirstChildElement("center")->FloatAttribute("x");
        s->m_p.y = elm->FirstChildElement("center")->FloatAttribute("y");
        s->m_radius = elm->FirstChildElement("radius")->FloatAttribute("value");
    }

    if(type == b2Shape::e_edge){
        b2EdgeShape* s = new b2EdgeShape;
        shape = s;
        s->m_vertex1.x = elm->FirstChildElement("v1")->FloatAttribute("x");
        s->m_vertex1.y = elm->FirstChildElement("v1")->FloatAttribute("y");
        s->m_vertex2.x = elm->FirstChildElement("v2")->FloatAttribute("x");
        s->m_vertex2.y = elm->FirstChildElement("v2")->FloatAttribute("y");
    }

    if(type == b2Shape::e_polygon){
        b2PolygonShape* s = new b2PolygonShape;
        shape = s;
        XMLNode* n = elm->FirstChild();
        QVector<b2Vec2> vecs;
        while(n){
            XMLElement* vecElm = n->ToElement();
            b2Vec2 vec(vecElm->FloatAttribute("x"),vecElm->FloatAttribute("y"));
            vecs.append(vec);
            n = n->NextSibling();
        }
        s->Set(vecs.data(),vecs.size());
    }

    if(type == b2Shape::e_chain){
        b2ChainShape* s = new b2ChainShape;
        shape = s;
        XMLNode* n = elm->FirstChild();
        QVector<b2Vec2> vecs;
        while(n){
            XMLElement* vecElm = n->ToElement();
            b2Vec2 vec(vecElm->FloatAttribute("x"),vecElm->FloatAttribute("y"));
            vecs.append(vec);
            n = n->NextSibling();
        }
        s->CreateChain(vecs.data(),vecs.size());
    }

    return shape;
}

void NBDataMnger::writeFilter(tinyxml2::XMLDocument *dom, XMLNode *parent, string id, b2Filter *filter)
{
    using namespace tinyxml2;
    XMLElement* categoryBits = parent->LinkEndChild(dom->NewElement("categoryBits"))->ToElement();
    categoryBits->SetAttribute("value",filter->categoryBits);
    XMLElement* maskBits = parent->LinkEndChild(dom->NewElement("maskBits"))->ToElement();
    maskBits->SetAttribute("value",filter->maskBits);
    XMLElement* groupIndex = parent->LinkEndChild(dom->NewElement("groupIndex"))->ToElement();
    groupIndex->SetAttribute("value",filter->groupIndex);
}

void NBDataMnger::readFilter(XMLNode *node, b2Filter *filter)
{
    using namespace tinyxml2;
    XMLElement* elm = node->ToElement();
    filter->categoryBits = elm->FirstChildElement("categoryBits")->IntAttribute("value");
    filter->maskBits = elm->FirstChildElement("maskBits")->IntAttribute("value");
    filter->groupIndex = elm->FirstChildElement("groupIndex")->IntAttribute("value");
}

b2Shape *NBDataMnger::getShape(QString id)
{
    if(shapes.contains(id)){
        return shapes[id];
    }
    return nullptr;
}

b2Shape *NBDataMnger::getShapeClone(QString id)
{
    b2Shape* shape = getShape(id);
    if(shape == nullptr){
        return shape;
    }
    return shape->Clone(&blockAllocator);
}

QStringList NBDataMnger::getShapeList()
{
    return shapes.keys();
}

void NBDataMnger::draw(NQOpenGL2DWidget *widget)
{
    layer.draw(widget);
}
