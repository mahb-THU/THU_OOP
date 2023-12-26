#include"editor.h"
#include<iostream>
using namespace std;
//创建编辑器。初始状态下，文本为空（即没有任何文本，打印的时候表现为一个空行），光标位置为(0,0),处于非选中状态。
TextEditor::TextEditor(){
    cursorPos={0,0};
    data.push_back("\n");
    choice=false;
}
//光标之移动光标（MOVE）：接受一个位置，移动光标至该位置。若当前有选中区域，则先取消选中状态再移动光标。
void TextEditor::moveCursor(Position dest){
    if(choice==true){
        choice=false;
    }
    cursorPos=dest;
}
//光标之选择（SELECT）：接受两个位置beg、end，选中[beg,end)区域。空行包含一个换行符，被选中时应将其包含。在beg、end相等时，选中区域为空。
void TextEditor::select(Position beg, Position end){
    choicePos_1=beg;
    choicePos_2=end;
    choice=true;
}
//编辑之写入（WRITE）：接受一个字符串str，若无选中区域，则在光标处写入该字符串；若有选中区域，则替换之，即先删除再写入。写入完成后，光标均移动至写入内容末尾。
void TextEditor::write(const std::string& str){
    if(choice==true){
        //删除(同时已解除选中)
        del();
    }
    data[cursorPos.first].insert(cursorPos.second,str);
    //光标移动动至内容末尾
    moveCursor({cursorPos.first,cursorPos.second+str.size()});
}
/*换行（NEWLINE）：在光标所在行下方新插入一行，若无选中区域，则将光标所在行光标之后的字符移动至新行；
若有选中区域，则先删除再换行。换行后，光标位于新一行开头。*/
void TextEditor::newline(){
    if(choice==true){
        //删除(同时已解除选中)
        del();
    }
    string mid;
    mid=data[cursorPos.first].substr(cursorPos.second);
    data[cursorPos.first].erase(data[cursorPos.first].begin()+cursorPos.second,data[cursorPos.first].end()-1);
    data.insert(data.begin()+cursorPos.first+1,mid);
    //换行后，光标位于新一行开头
    moveCursor({cursorPos.first+1,0});
}
/*删除（DELETE）：若无选中区域，则删除光标位置的一个字符，光标位置不变；若有选中区域，则删除已选中的内容，同时退出选中状态，光标置于选中区域靠近开头的位置。
光标位于行末时，将会删除行末换行符，将其与下一行合并；而若光标位于最后一行行末，则不会有任何操作。*/
void TextEditor::del(){
    if(choice==false){
        //光标位于最后一行行末，无操作
        if(cursorPos.first!=data.size()-1||cursorPos.second!=data[data.size()-1].size()-1){
            //光标位于行末（非最后一行）
            if(cursorPos.second==(data[cursorPos.first].size()-1)){
                data[cursorPos.first].pop_back();
                data[cursorPos.first]+=data[cursorPos.first+1];
                data.erase(data.begin()+cursorPos.first+1);
            }else{
                data[cursorPos.first].erase(data[cursorPos.first].begin()+cursorPos.second);
            }
        }
        //光标位置不变
    }else{
            string deletefront;
            string deletebehind;
            deletefront=data[choicePos_1.first].substr(0,choicePos_1.second);
            deletebehind=data[choicePos_2.first].substr(choicePos_2.second);
            string deleteafter=deletefront+deletebehind;
            data.erase(data.begin()+choicePos_1.first,data.begin()+choicePos_2.first+1);
            data.insert(data.begin()+choicePos_1.first,deleteafter);
            moveCursor(choicePos_1);
    }
    //只要是删除，无论如何都要退出选中状态
    choice=false;
}
//复制（COPY）：如果有选中区域，复制选中区域的内容至剪贴板，如果剪切板之前有内容则覆盖之。若无选中区域，则无任何影响。
void TextEditor::copy(){
    if(choice==true){
        //删除剪切板内容(覆盖)
        clipboard.clear();
        clipboard.shrink_to_fit();
        if(choicePos_2.first-choicePos_1.first==0){
            clipboard.insert(clipboard.begin(),data[choicePos_1.first].substr(choicePos_1.second,choicePos_2.second-choicePos_1.second));
        }else if(choicePos_2.first-choicePos_1.first==1){
            clipboard.insert(clipboard.begin(),data[choicePos_1.first].substr(choicePos_1.second));
            clipboard.insert(clipboard.begin()+1,data[choicePos_1.first+1].substr(0,choicePos_2.second));
        }else{
            for(int i=0;i<choicePos_2.first-choicePos_1.first+1;i++){
                if(i==0){
                    clipboard.insert(clipboard.begin(),data[choicePos_1.first].substr(choicePos_1.second));
                }else if(i==choicePos_2.first-choicePos_1.first){
                    clipboard.insert(clipboard.begin()+i,data[choicePos_1.first+i].substr(0,choicePos_2.second));
                }else{
                    clipboard.insert(clipboard.begin()+i,data[choicePos_1.first+i].substr());
                }
            }
        }
        // if(clipboard[clipboard.size()-1].empty()){
        //     clipboard.pop_back();
        // }
    }
}
/*粘贴（PASTE）：若无选中区域，将剪贴板现有内容粘贴到光标处；若有选中区域，则替换之，即先删除再粘贴。
剪贴板为空时不产生任何写入操作，但是可以将选中区域清除。在粘贴完成后，光标移动到粘贴内容末尾。*/
void TextEditor::paste(){
    if(clipboard.empty()){
        if(choice==true){
            del();
        }
    }else{
        if(choice==true){
            //先删除
            del();
        }
        //再粘贴
        if (clipboard.empty()) {
            return;
        }
        string pastefront;
        string pastebehind;
        pastefront=data[cursorPos.first].substr(0,cursorPos.second);
        pastebehind=data[cursorPos.first].substr(cursorPos.second);
        data.erase(data.begin()+cursorPos.first);
        for(int i=0;i<clipboard.size();i++){
            data.insert(data.begin()+cursorPos.first+i,clipboard[i]);
        }
        data[cursorPos.first].insert(0,pastefront);
        data[cursorPos.first+clipboard.size()-1].append(pastebehind);
        //光标移动至粘贴内容末尾
        if(clipboard.size()==1){
            moveCursor({cursorPos.first,cursorPos.second+clipboard[0].size()});
        }else{
            moveCursor({cursorPos.first+clipboard.size()-1,clipboard[clipboard.size()-1].size()});
        }
    }
}
//编辑之截屏（SCREEN）：将目前文本编辑器处理得到的文本逐行输出至标准输出。用*标出光标的位置或选中区域的位置。
void TextEditor::screenShot(){
    vector<string> printdata;
    for(int i=0;i<data.size();i++){
        printdata.push_back(data[i]);
    }
    //用*标出光标的位置或选中区域的位置
    if(choice==false){
        printdata[cursorPos.first].insert(cursorPos.second,"*");
    }else
        if(choicePos_1==choicePos_2){
            printdata[choicePos_1.first].insert(choicePos_1.second,"**");
        }else{{
            if(choicePos_1.first!=choicePos_2.first){
                printdata[choicePos_1.first].insert(choicePos_1.second,"*");
                printdata[choicePos_2.first].insert(choicePos_2.second,"*");
            }else{
                printdata[choicePos_1.first].insert(choicePos_1.second,"*");
                printdata[choicePos_2.first].insert(choicePos_2.second+1,"*");
            }
        }
    }
    //显式删除最后一个换行符
    printdata[printdata.size()-1].pop_back();
    //打印
    for(int i=0;i<printdata.size();i++){
        cout<<printdata[i];
    }
}