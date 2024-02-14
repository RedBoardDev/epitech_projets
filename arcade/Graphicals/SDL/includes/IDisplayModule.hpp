#pragma once

#include <vector>
#include <iostream>

namespace Arcade {
    namespace Graphics {
        class IDisplayModule {
            public:
                /**
                 * @brief
                 * All getable events by the IdisplayModule
                 * 
                 */
                enum Events {
                    A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,
                    keyUp,
                    keyDown,
                    keyLeft,
                    keyRight,
                    key1,
                    key2,
                    key3,
                    key4,
                    key5,
                    key6,
                    key7,
                    key8,
                    key9,
                    key0,
                    keySpace,
                    keyEscape,
                    keyEnter,
                    rightClic,
                    leftClic,
                    backSpace,
                    close
                };
                /**
                 * @brief Destroy the IDisplayModule object
                 * 
                 */
                virtual ~IDisplayModule() = default;
                /**
                 * @brief Set the Frame Rate Limit object
                 * 
                 * @param limit
                 */
                virtual void setFrameRateLimit(int limit) = 0;
                /**
                 * @brief put a pixel on the window
                 * 
                 * @param x 
                 * @param y 
                 * @param color 
                 */
                virtual void putpixel(int x, int y, unsigned int color) = 0;
                /**
                 * @brief Get the events
                 * 
                 * @return std::vector<Events> 
                 */
                virtual std::vector<Events> getEvents() = 0;
                /**
                 * @brief return the window statue
                 * 
                 * @return true 
                 * @return false 
                 */
                virtual bool isOpen() = 0;
                /**
                 * @brief clear the window
                 * 
                 */
                virtual void clearWin() = 0;
                /**
                 * @brief refresh the window
                 * 
                 */
                virtual void refreshWin() = 0;
                /**
                 * @brief put text on the window
                 * 
                 * @param x 
                 * @param y 
                 * @param color 
                 * @param str 
                 */
                virtual void puttext(int x, int y, unsigned int color, const std::string &str) = 0;
                /**
                 * @brief Get the Mouse Pos objectget mouse position relative to the window
                 * 
                 * @return std::pair<int, int> 
                 */
                virtual std::pair<int, int> getMousePos() = 0;
        };
    }
}
