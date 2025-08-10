import os
import re
import argparse
from jinja2 import Environment, FileSystemLoader

SVG_DIR = os.path.join(os.path.dirname(__file__), "svgs")


def make_identifier(filename):
    name = os.path.splitext(filename)[0]
    # Uppercase and replace non-alphanumeric with underscores
    return re.sub(r"[^A-Z0-9_]", "_", name.upper())


def collect_svgs(svg_dir):
    entries = []
    for fname in os.listdir(svg_dir):
        if fname.lower().endswith(".svg"):
            path = os.path.join(svg_dir, fname)
            with open(path, "r", encoding="utf-8") as f:
                data = f.read()
            ident = make_identifier(fname)
            entries.append({"ident": ident, "data": data})
    return entries


def main(output_header, template_dir="."):
    env = Environment(
        loader=FileSystemLoader(template_dir), trim_blocks=True, lstrip_blocks=True
    )
    tmpl = env.get_template("svg_header.jinja")
    svgs = collect_svgs(SVG_DIR)
    rendered = tmpl.render(icons=svgs)
    with open(output_header, "w", encoding="utf-8") as f:
        f.write(rendered)
    print(f"Generated {output_header} with {len(svgs)} SVGs.")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Generate C++ header with embedded SVGs."
    )
    parser.add_argument("--out", default="../src/svgs.h", help="Output header file")
    parser.add_argument(
        "--tmpl-dir", default=".", help="Directory containing the Jinja template"
    )
    args = parser.parse_args()
    main(args.out, args.tmpl_dir)
