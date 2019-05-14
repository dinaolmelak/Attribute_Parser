//
//  main.cpp
//  Attribute_Parser
//
//  Created by Dinaol Melak on 5/13/19.
//  Copyright © 2019 Dinaol Melak. All rights reserved.
//
//We have defined our own markup language HRML. In HRML, each element consists of a starting and ending tag, and there are attributes associated with each tag. Only starting tags can have attributes. We can call an attribute by referencing the tag, followed by a tilde, '~' and the name of the attribute. The tags may also be nested.
//
//The opening tags follow the format:
//
///<tag-name attribute1-name = "value1" attribute2-name = "value2" ...>
//
//The closing tags follow the format:
//
///</tag-name>
#include <cmath>
#include <cstring>
#include <sstream>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class attribute{
private:
    string attributeName;
    string value;
    attribute *nextAttrPtr;
public:
    attribute(){
        
    }
    void setAttribute(string name,string value){
        this->attributeName = name;
        this->value = value;
    }
    void setAttributeName(string attrNameIn){
        this->attributeName = attrNameIn;
    }
    void setAttributeValue(string attrValueIn){
        this->value = attrValueIn;
    }
    string getAttributeName(){
        return this->attributeName;
    }
    string getAttributeValue(){
        return this->value;
    }
    void setNextAttrPtr(attribute *nextAttr){
        this->nextAttrPtr=nextAttr;
    }
    attribute* getNextAttrPtr(){
        return nextAttrPtr;
    }
    
    
};


class tag{
private:
    string tagName;
    attribute tagAttribute;
    attribute *nextTagAttributePtr;
    string closingTagName;
public:
    tag(){
        nextTagAttributePtr->setNextAttrPtr(0);
    }
    void setTag(string tagStr){
///<tag-name attribute1-name = "value1" attribute2-name = "value2" ...>
        string myAttr,myTag,myValue;
        char mySwitchTrigger = 'Z';
        for(int i=0;i<tagStr.length();i++){
            switch (mySwitchTrigger){
                case 'A':
                    if(tagStr[i] == '='&& tagStr[i+1] == ' '){
                        
                    }else if(tagStr[i] == ' '&& tagStr[i+1]!='"'){
                        
                    }else if(tagStr[i] == ' '&& tagStr[i+1]=='"'){
                        mySwitchTrigger = 'V';
                    }
                    else{
                        myAttr += tagStr[i];
                    }
                    break;
                case 'T':
                    if(tagStr[i]==' '){
                        mySwitchTrigger = 'A';
                    }else{
                        myTag += tagStr[i];
                    }
                    break;
                case 'V':
                    if(tagStr[i] == '"' && tagStr[i+1] != '>'){
                        mySwitchTrigger = 'O';
                    }else if(tagStr[i] == '"' && tagStr[i+1] == '>'){
                        mySwitchTrigger = 'Z';
                    }else{
                        myValue += tagStr[i];
                    }
                    break;
                case 'O':
                    
                    break;
                default:
                    if(tagStr[i]=='<'){
                        mySwitchTrigger = 'T';
                    }else if (tagStr[i] == '>'){
                        
                    }
                    break;
                    
            }
        }
        
    }
    void printTag(){
        cout<<tagName<<endl<<tagAttribute.getAttributeName()<<":"<<tagAttribute.getAttributeValue()<<endl;
        
    }
    
};

int main() {
    string str;
    cout<<"str please!\n";
    getline(cin,str);
    
    
    string myTag,myAttr,myValue;
    
    char mySwitchTrigger = 'Z';
    for(int i=0;i<str.length();i++){
        switch (mySwitchTrigger){
            case 'A':
                if(str[i] == '='&& str[i+1] == ' '){
                    
                }else if(str[i] == ' '&& str[i+1]!='"'){
                    
                }else if(str[i] == ' '&& str[i+1]=='"'){
                    mySwitchTrigger = 'V';
                }
                else{
                    myAttr += str[i];
                }
                break;
            case 'T':
                if(str[i]==' '){
                    mySwitchTrigger = 'A';
                }else{
                    myTag += str[i];
                }
                break;
            case 'V':
                if(str[i] == '"' && str[i+1] != '>'){
                    //mySwitchTrigger = 'O';
                }else if(str[i] == '"' && str[i+1] == '>'){
                    mySwitchTrigger = 'Z';
                }else{
                    myValue += str[i];
                }
                break;
                //case 'O':
                
                //    break;
            default:
                if(str[i]=='<'){
                    mySwitchTrigger = 'T';
                }else if (str[i] == '>'){
                    
                }
                break;
                
        }
    }
    cout<<"myTag:"<<myTag<<"myAttr:"<<myAttr<<"myVal:"<<myValue;
    
    
    return 0;
}


/*
 for(int i=0;i<str.length();i++){
 if(str[0]=='<'&&str[1]!='/'){
 if(str[i]!='<'&&str[i]!=' '){
 tag1+=str[i];
 }
 if(str[i]==' '){
 while(str[i+1]!='='){
 attr1+=str[i];
 }
 }else if(str[i]==' '&&str[i+1]=='"'){
 while(str[i+1]!='"'){
 value1+=str[i];
 }
 }
 }
 
 }
 */
