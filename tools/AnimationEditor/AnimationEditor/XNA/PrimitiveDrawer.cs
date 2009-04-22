using System;
using System.Collections.Generic;
using System.Windows.Forms;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Content;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;

namespace AnimationEditor
{
    public static class PrimitiveDrawer
    {
        public static PrimitiveBatch primBatch;

        public static void Initialize(GraphicsDevice graphicsDevice)
        {
            primBatch = new PrimitiveBatch(graphicsDevice);
        }

        public static void DrawRectangle(Vector2 upperLeft, float width, float height, Color color)
        {
            if (primBatch != null)
            {
                primBatch.Begin(PrimitiveType.LineList);

                primBatch.AddVertex(upperLeft, color);
                primBatch.AddVertex(new Vector2(upperLeft.X + width, upperLeft.Y), color);

                primBatch.AddVertex(new Vector2(upperLeft.X + width, upperLeft.Y), color);
                primBatch.AddVertex(new Vector2(upperLeft.X + width, upperLeft.Y + height), color);

                primBatch.AddVertex(new Vector2(upperLeft.X + width, upperLeft.Y + height), color);
                primBatch.AddVertex(new Vector2(upperLeft.X, upperLeft.Y + height), color);

                primBatch.AddVertex(new Vector2(upperLeft.X, upperLeft.Y + height), color);
                primBatch.AddVertex(upperLeft, color);

                primBatch.End();
            }
        }
    }
}