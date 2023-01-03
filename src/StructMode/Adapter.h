/**
 * 适配器模式：Adapter Pattern: 作为两个不兼容的接口之间的桥梁。这种类型的设计模式属于结构型模式，它结合了两个独立接口的功能。
                              这种模式涉及到一个单一的类，该类负责加入独立的或不兼容的接口功能
 *
 * 意图：将一个类的接口转换成客户希望的另外一个接口。适配器模式使得原本由于接口不兼容而不能一起工作的那些类可以一起工作。
 * 主要解决：主要解决在软件系统中，常常要将一些"现存的对象"放到新的环境中，而新环境要求的接口是现对象不能满足的。
 * 何时使用：
    * 1、系统需要使用现有的类，而此类的接口不符合系统的需要。
    * 2、想要建立一个可以重复使用的类，用于与一些彼此之间没有太大关联的一些类，包括一些可能在将来引进的类一起工作，这些源类不一定有一致的接口。
    * 3、通过接口转换，将一个类插入另一个类系中。（比如老虎和飞禽，现在多了一个飞虎，在不增加实体的需求下，增加一个适配器，在里面包容一个虎对象，实现飞的接口。）
 * 如何解决：继承或依赖（推荐）。
 * 关键代码：适配器继承或依赖已有的对象，实现想要的目标接口。
 * 应用实例：
    * 1、美国电器 110V，中国 220V，就要有一个适配器将 110V 转化为 220V。
    * 2、在 LINUX 上运行 WINDOWS 程序。
 * 优点：
    * 1、可以让任何两个没有关联的类一起运行。
    * 2、提高了类的复用。
    * 3、增加了类的透明度。
    * 4、灵活性好。
 * 缺点：
    * 1、过多地使用适配器，会让系统非常零乱，不易整体进行把握。比如，明明看到调用的是 A 接口，其实内部被适配成了 B 接口的实现，一个系统如果太多出现这种情况，无异于一场灾难。因此如果不是很有必要，可以不使用适配器，而是直接对系统进行重构。
 * 使用场景：有动机地修改一个正常运行的系统的接口，这时应该考虑使用适配器模式。
 * 注意事项：适配器不是在详细设计时添加的，而是解决正在服役的项目的问题。
 */

#pragma once
#include <iostream>
#include <string>

/**
 * 原有Audio Player，增加了Advanced Media Player
 * 现在想让 Audio Player 可以播放所有格式的文件
 */
namespace DP {

///================================================
class MediaPlayer {
public:
    virtual void play(const std::string& type, const std::string& file) {}
};

class AdvancedMediaPlayer {
public:
    virtual void playVlc(const std::string& file) { };
    virtual void playMP4(const std::string& file) { };
};

///================================================
class VlcPlayer : public AdvancedMediaPlayer {
public:
    void playVlc(const std::string& file) override {
        std::cout <<  "Play type: vlc, file: " << file << std::endl;
    }

    void playMP4(const std::string& file) override { }
};

class Mp4Player : public AdvancedMediaPlayer {
public:
    void playVlc(const std::string& file) override { }

    void playMP4(const std::string& file) override {
        std::cout << "Play type: mp4, file: " << file << std::endl;
    }
};

///================================================
class MediaPlayerAdapter : public MediaPlayer {
public:
    MediaPlayerAdapter(const std::string& type) {
        if(type == "vlc") {
            adv_media_player_ = new VlcPlayer();
        } else if(type == "mp4") {
            adv_media_player_ = new Mp4Player();
        }
    }

    void play(const std::string& type, const std::string& file) override {
        if(type == "vlc") {
            adv_media_player_->playVlc(file);
        } else if(type == "mp4") {
            adv_media_player_->playMP4(file);
        }
    }

private:
    AdvancedMediaPlayer* adv_media_player_ = nullptr;
};

///================================================
class AudioPlayer : public MediaPlayer {
public:
    void play(const std::string& type, const std::string& file) override {
        if(type == "mp3") {
            std::cout << "Play type: " << type << ", File: " << file << std::endl;
        } else if(type == "vlc" || type == "mp4") {
            media_adapter_ = new MediaPlayerAdapter(type);
            media_adapter_->play(type, file);
        } else {
            std::cout << "The type " << type << " is invalid !!" << std::endl;
        }

    }

private:
    MediaPlayerAdapter* media_adapter_ = nullptr;
};
}