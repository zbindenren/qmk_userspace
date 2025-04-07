// Package converts the layout yaml to C code
package main

import (
	"fmt"
	"log/slog"
	"maps"
	"os"
	"slices"
	"strconv"
	"strings"

	"gopkg.in/yaml.v3"
)

// source: https://github.com/qmk/qmk_firmware/blob/master/keyboards/crkbd/rev4_1/standard/keyboard.json
var (
	left = []string{
		"[3, 5]",
		"[2, 5]",
		"[1, 5]",
		"[0, 5]",
		"[0, 4]",
		"[1, 4]",
		"[2, 4]",
		"[3, 4]",
		"[3, 3]",
		"[2, 3]",
		"[1, 3]",
		"[0, 3]",
		"[0, 2]",
		"[1, 2]",
		"[2, 2]",
		"[2, 1]",
		"[1, 1]",
		"[0, 1]",
		"[0, 0]",
		"[1, 0]",
		"[2, 0]",
		"[0, 6]",
		"[1, 6]",
	}
	right = []string{
		"[7, 5]",
		"[6, 5]",
		"[5, 5]",
		"[4, 5]",
		"[4, 4]",
		"[5, 4]",
		"[6, 4]",
		"[7, 4]",
		"[7, 3]",
		"[6, 3]",
		"[5, 3]",
		"[4, 3]",
		"[4, 2]",
		"[5, 2]",
		"[6, 2]",
		"[6, 1]",
		"[5, 1]",
		"[4, 1]",
		"[4, 0]",
		"[5, 0]",
		"[6, 0]",
		"[4, 6]",
		"[5, 6]",
	}
)

type Layer struct {
	Layer int        `yaml:"layer"`
	Left  [][]string `yaml:"left"`
	Right [][]string `yaml:"right"`
}

func (l Layer) colMap(side string) map[string]string {
	rowOffset := 0
	if side == "right" {
		rowOffset = 4
	}

	m := map[string]string{}
	var s [][]string

	switch side {
	case "right":
		s = l.Right

		// reverse slice for the right side
		for i := range l.Right {
			row := l.Right[i]
			slices.Reverse(row)
		}
	default:
		s = l.Left
	}

	for row := range s {
		for col, val := range s[row] {
			key := fmt.Sprintf("[%d, %d]", row+rowOffset, col)
			m[key] = val
		}
	}

	return m
}

func (l Layer) colList() ([]string, error) {
	list := make([]string, 23*2)
	coordinates := append(left, right...)
	m := map[string]string{}

	for _, halve := range []string{"left", "right"} {
		maps.Copy(m, l.colMap(halve))
	}

	for i, v := range coordinates {
		col, ok := m[v]
		if !ok {
			return nil, fmt.Errorf("key found: %s", v)
		}

		if col == "---" {
			return nil, fmt.Errorf("invalid: %s", v)
		}

		list[i] = col
	}

	return list, nil
}

func (l Layer) cArray() (string, error) {
	var b strings.Builder
	b.WriteString("[")
	b.WriteString(strconv.Itoa(l.Layer))
	b.WriteString("] = { ")

	colList, err := l.colList()
	if err != nil {
		return "", err
	}

	for i, c := range colList {
		b.WriteString("{LC_")
		b.WriteString(c)
		if i < len(colList)-1 {
			b.WriteString("}, ")

			continue
		}
		b.WriteString("}")
	}
	b.WriteString(" },")

	return b.String(), nil
}

type Layers []Layer

const (
	layoutFile = "layout.yaml"
)

func main() {
	d, err := os.ReadFile(layoutFile)
	if err != nil {
		slog.Error("failed to open file", "file", layoutFile, "err", err)

		os.Exit(1)
	}

	var layers []Layer
	err = yaml.Unmarshal(d, &layers)
	if err != nil {
		slog.Error("failed to open file", "file", layoutFile, "err", err)

		os.Exit(1)
	}

	for _, l := range layers {
		a, err := l.cArray()
		if err != nil {
			slog.Error("render failed", "err", err)

			os.Exit(1)
		}
		fmt.Println(a)
		fmt.Println()
	}
}
